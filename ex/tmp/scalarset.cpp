/******************************
  Program "scalarset.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Jul  9 2014"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Jul  9 2014"
#define PROTOCOL_NAME "scalarset"
#define BITS_IN_WORLD 8
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_a: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_a& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_a& val)
    {
      if (val.defined())
	return ( s << mu_1_a::values[ int(val) - 1 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_a (const char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_a (void): mu__byte(1, 3, 2) {};
  mu_1_a (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_a& a, mu_1_a& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_a::values[] =
  { "a_1","a_2","a_3",NULL };

/*** end scalarset declaration ***/
mu_1_a mu_1_a_undefined_var;

const int mu_a_1 = 1;
const int mu_a_2 = 2;
const int mu_a_3 = 3;
/*** Variable declaration ***/
mu_1_a mu_arr("arr",0);





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_arr.clear();
}
void world_class::undefine()
{
  mu_arr.undefine();
}
void world_class::reset()
{
  mu_arr.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_arr.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_arr.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_arr.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_arr.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_0_boolean mu_x;
    mu_x.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("bar, x:%s", mu_x.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_0_boolean mu_x;
    mu_x.value((r % 2) + 0);
    r = r / 2;
    return 1;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_0_boolean mu_x;
    mu_x.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 2 )
      {
	if ( ( TRUE  ) ) {
	      if (1) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 2;
	}
	else
	  what_rule += 2;
    r = what_rule - 0;
    mu_x.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_0_boolean mu_x;
    mu_x.value((r % 2) + 0);
    r = r / 2;
mu_arr.undefine();
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<2)
    { R0.NextRule(what_rule);
      if (what_rule<2) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=1) return R0.Condition(r-0);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=1) { R0.Code(r-0); return; } 
}
int Priority(unsigned short r)
{
  if (r<=1) { return R0.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=1) return R0.Name(r-0);
  return NULL;
}
};
const unsigned numrules = 2;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 2


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("foo");
  }
  void Code(unsigned short r)
  {
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
const rulerec invariants[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numinvariants = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
arr:ScalarsetVariable
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_a[3];
  int undefined_class_mu_1_a;// has the highest class number

  void Print_class_mu_1_a();
  bool OnlyOneRemain_mu_1_a;
  bool MTO_class_mu_1_a()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_a)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_a[i]== class_mu_1_a[j])
	    return TRUE;
    OnlyOneRemain_mu_1_a = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_a;
  typedef int arr_mu_1_a[3];
  arr_mu_1_a * perm_mu_1_a;
  arr_mu_1_a * revperm_mu_1_a;

  int size_mu_1_a[3];
  bool reversed_sorted_mu_1_a(int start, int end);
  void reverse_reversed_mu_1_a(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_a* perm, int size, mu_1_a k);
  void GenPerm0(mu_1_a* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_a()
{
  cout << "class_mu_1_a:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_a[i];
  cout << " " << undefined_class_mu_1_a << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_a[i]== class_mu_1_a[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
    mu_1_a Perm0[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[6];
 in_mu_1_a = new int[6];
 perm_mu_1_a = new arr_mu_1_a[6];
 revperm_mu_1_a = new arr_mu_1_a[6];

    // Set perm and revperm
    count = 0;
    for (i=1; i<=3; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=1; j<=3; j++)
        for (k=1; k<=3; k++)
          if (revperm_mu_1_a[i][k-1]==j)   // k - base 
            perm_mu_1_a[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_a = 0;
    size = 6;
    count = 6;
    for (i=0; i<6; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_a[i] = i_mu_1_a;
      i_mu_1_a += carry;
      if (i_mu_1_a >= 6) { i_mu_1_a = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_a = new int[1];
 perm_mu_1_a = new arr_mu_1_a[1];
 revperm_mu_1_a = new arr_mu_1_a[1];
  in[0] = TRUE;
    in_mu_1_a[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<3; i++)
    class_mu_1_a[i]=0;
  undefined_class_mu_1_a=0;
  OnlyOneRemain_mu_1_a = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<6; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_a[3];
  int size_mu_1_a[3];
  bool should_be_in_mu_1_a[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_a; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_a[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_a[k]==j)
	  {
	    size_mu_1_a[k] = class_size;
	    start_mu_1_a[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_a[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_a[i][k]-1 >=start_mu_1_a[k] 
	     && perm_mu_1_a[i][k]-1 < start_mu_1_a[k] + size_mu_1_a[k]) )
  	    {
	      should_be_in_mu_1_a[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<6; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_a[in_mu_1_a[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_a; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_a[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_a[k]==j)
	  {
	    size_mu_1_a[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_a; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_a[k]==j)
	      revperm_mu_1_a[0][start++] = k+1;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_a[0][k]==j+1)
        perm_mu_1_a[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_a* Perm, int size, mu_1_a k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_a* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=1; i<=3; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=3; i++)
        revperm_mu_1_a[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_a(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_a[0][i]<revperm_mu_1_a[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_a(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_a[0][j];
      revperm_mu_1_a[0][j] = revperm_mu_1_a[0][i];
      revperm_mu_1_a[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_a[revperm_mu_1_a[0][start]-1];
      if (reversed_sorted_mu_1_a(start,end))
	       {
	  reverse_reversed_mu_1_a(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_a(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_a[0][j]<revperm_mu_1_a[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_a[0][j];
			  revperm_mu_1_a[0][j] = revperm_mu_1_a[0][k];
			  revperm_mu_1_a[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_a(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_a[0][k]==j+1)   // k - base 
	perm_mu_1_a[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_arr.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_a::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_a[Perm.in_mu_1_a[i]][value()-1]); // value - base
};
void mu_1_a::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_a[value()-1]==Perm.undefined_class_mu_1_a) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_a[i] == Perm.undefined_class_mu_1_a && i!=value()-1)
            Perm.class_mu_1_a[i]++;
        value(1 + Perm.undefined_class_mu_1_a++);
      }
    else 
      {
        value(Perm.class_mu_1_a[value()-1]+1);
      }
}
void mu_1_a::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_a::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_a[value()-1]==Perm.undefined_class_mu_1_a) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_a[i] == Perm.undefined_class_mu_1_a && i!=value()-1)
            Perm.class_mu_1_a[i]++;
        Perm.undefined_class_mu_1_a++;
      }
}
void mu_1_a::ArrayLimit(PermSet& Perm) {}
void mu_1_a::Limit(PermSet& Perm) {}
void mu_1_a::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_arr.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_arr.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_arr.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_arr.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_arr.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_arr.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_arr.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_arr.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_arr.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_arr.SimpleCanonicalize(Perm);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_arr.SimpleCanonicalize(Perm);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_arr.SimpleCanonicalize(Perm);

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"
