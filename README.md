CMurphi (Caching Murphi) is a model checker developed on the top of Murphi.

The original Murphi web page is [here](http://verify.stanford.edu/dill/murphi.html), while a more up-to-date page is [here](http://www.cs.utah.edu/formal_verification/softwareopensource/murphi/).

CMurphi implements two new model checking algorithms. The first one has been obtained from Murphi 3.1 release by replacing Murphi Hash Table with a Cache and Murphi RAM queue with a disk queue. The second one is disk based. Both are described in [STTT 2004](http://mclab.di.uniroma1.it/publications/show.php?record=91).

The current version of CMurphi is a refactored one:

- it corrects some errors coming out with newer versions of g++
- it supports 64-bit architectures also when using hash compaction
- it includes [FHP-Murphi](http://mclab.di.uniroma1.it/site/index.php/software/17-fhp-murphi)

