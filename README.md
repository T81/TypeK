# Type K thermocouples linearization library for Arduino

Provides support for [ITS-90](https://srdata.nist.gov/its90/download/type_K.tab) thermocouple linearization,
[Type K](https://en.wikipedia.org/wiki/Thermocouple#Type_K) thermocouples.


### Includes functions to:
 - convert a mV reading into an absolute temperature (C or F)
 - convert a mV reading + ambient temp reading to a compensated sensor temperature
 - convert a temperature (C or F) into the corresponding mV value

Author: Jim Gallt ([tc4-shield] (https://code.google.com/archive/p/tc4-shield/))