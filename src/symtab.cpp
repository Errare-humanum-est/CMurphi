/**CFile***********************************************************************

  FileName    [symtab.cpp]

  Synopsis    [File for parsing symbol table]

  Author      [Igor Melatti]

  Copyright   [
  This file is part of the compiler package of CMurphi. 
  Copyright (C) 2009-2012 by Sapienza University of Rome. 

  CMurphi is free software; you can redistribute it and/or 
  modify it under the terms of the GNU Lesser General Public 
  License as published by the Free Software Foundation; either 
  of the License, or (at your option) any later version.

  CMurphi is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public 
  License along with this library; if not, write to the Free Software 
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA.

  To contact the CMurphi development board, email to <melatti@di.uniroma1.it>. ]

******************************************************************************/

#include "mu.hpp"

// #define DEBUG_SYMTAB

/********************
  class ste
  ********************/
ste::ste(lexid * name, int scope, decl * value)
:name(name), scope(scope), value(value), next(NULL)
{
  if (value != NULL) {		/* IM: added condition on value, for external calls */
    /* a weirdness--we tell an object its name when we declare it. */
    if (name != NULL)
      value->name = name->getname();	/* loses a previous name for value. */
    if (value->getclass() != decl::Type)
      value->mu_name = tsprintf("mu_%s", value->name);
    else if (value != booltype)
      value->mu_name = tsprintf("mu_%d_%s", scope, value->name);
  }
}

ste *ste::search(lexid * name)
{
  ste *s = this;
  while (s != NULL && s->name != name)
    s = s->next;
  return s;
}

ste *ste::reverse()
{
  ste *in = this, *out = NULL, *temp = NULL;
  while (in != NULL) {
    temp = in;
    in = in->next;
    temp->next = out;
    out = temp;
  }
  return out;
}

/********************
  class symboltable
  ********************/
symboltable::symboltable()
{
  constdecl *temp;
  int i = 0;
  for (i = 0; i < MAXSCOPES; i++) {
    scopes[i] = 0;
    scopestack[i] = NULL;
  }
  curscope = 0;
  scopedepth = 0;

  /* enter useful stuff. */
  declare(ltable.enter("boolean"), booltype);
  temp = new constdecl(1, booltype);
  declare(ltable.enter("true"), temp);
  temp = new constdecl(0, booltype);
  declare(ltable.enter("false"), temp);
  ::offset = 0;
}

ste *symboltable::find(lexid * name) const
{
  ste *p = topste();
  while (p != NULL && p->name != name)
    p = p->next;
  return (p);
}

ste *symboltable::lookup(lexid * name)
{
  ste *p = find(name);
  if (p == NULL) {
    Error.Error("%s undeclared.", name->getname());
    p = declare(name, errordecl);
  }
  return (p);
}

ste *symboltable::declare(lexid * name, decl * value)
{
  ste *p = find(name);
#ifdef DEBUG_SYMTAB
  printf("Declaring %s in scope %d, depth %d\n",
	 name->getname(), scopes[scopedepth], scopedepth);
#endif
  if (p != NULL && p->getscope() == curscope) {
    Error.Error("%s already defined in current scope.", name->getname());
    return (p);
  }
  /* p is NULL here; no problem with reallocating it. */
  p = new ste(name, scopes[scopedepth], value);

  /* straightforward insertions. */
  p->next = topste();
  scopestack[scopedepth] = p;
  return (p);
}

ste *symboltable::declare_global(lexid * name, decl * value)
{
  ste *p = find(name);
  // ste **pp = NULL;
#ifdef DEBUG_SYMTAB
  printf("Declaring %s globally in scope %d, depth %d\n",
	 name->getname(), scopes[globalscope], globalscope);
#endif
  if (p != NULL && p->getscope() == globalscope) {
    Error.Error("%s already defined in global scope.", name->getname());
    return (p);
  }
  /* p is NULL here; no problem with reallocating it. */
  p = new ste(name, scopes[globalscope], value);

  /* not-quite-so-straightforward insertions. */
  // then insert it into the list.
  p->next = scopestack[globalscope];
  ste *oldtop = scopestack[globalscope];
  scopestack[globalscope] = p;

  // splice in the new ste into the list.  Ooh, this is going to be a pain.
  int i = globalscope + 1;
  ste *q = NULL;
  while (scopestack[i] == oldtop) {
    scopestack[i] = p;
    i++;
  }
  if (i <= scopedepth) {
    q = scopestack[i];
    while (q->next->scope == q->scope) {
      q = q->next;
    }
    q->next = p;
  }
  return (p);
}

int symboltable::pushscope()
{
  scopedepth++;
  curscope++;
  scopes[scopedepth] = curscope;
  // class of the group of variables to be declared -- for dependency analysis
  scopestack[scopedepth] = scopestack[scopedepth - 1];
  offsets[scopedepth - 1] = offset;
  offset = 0;
  return curscope;
}

ste *symboltable::popscope(bool cut)
/* take the ste's out of the hash table, but leave them in the linked list,
 * unless cut is set.*/
{
  ste **p;
  if (scopedepth <= 0) {
    Error.Error("Internal: Popped too many scopes. Giving up; sorry.");
    exit(1);
  }
  for (p = &scopestack[scopedepth];; p = &(*p)->next)
    /* Invariant: *p is the first element in the list for its bucket. */
  {
    if ((*p)->scope != scopes[scopedepth]) {
      if (cut)
	*p = NULL;
      break;
    }
  };
  offset = offsets[scopedepth - 1];
  return scopestack[scopedepth--];
}

ste *symboltable::getscope() const
{
  if (scopestack[scopedepth]->scope != scopes[scopedepth])
    return NULL;
  else
    return scopestack[scopedepth];
}

ste *symboltable::dupscope() const
{
  ste *s = getscope();
  ste *beginning = NULL, **end = &beginning;
  for (; s != NULL && s->scope == scopes[scopedepth]; s = s->next) {
    *end = new ste(s->name, s->scope, s->value);
    end = &(*end)->next;
  }
  return beginning;
}

ste *symboltable::dupscopereverse() const
{
  ste *s = dupscope();
  if (s == NULL) return NULL;
  return s->reverse();
}

const int symboltable::globalscope = 1;

