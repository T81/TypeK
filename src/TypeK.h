// Thermocouple library per ITS-90
// Version:  20100625

// *** BSD License ***
// ------------------------------------------------------------------------------------------
// Copyright (c) 2010, MLG Properties, LLC
// All rights reserved.
//
// Contributor:  Jim Gallt
//
// Redistribution and use in source and binary forms, with or without modification, are 
// permitted provided that the following conditions are met:
//
//   Redistributions of source code must retain the above copyright notice, this list of 
//   conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright notice, this list 
//   of conditions and the following disclaimer in the documentation and/or other materials 
//   provided with the distribution.
//
//   Neither the name of the MLG Properties, LLC nor the names of its contributors may be 
//   used to endorse or promote products derived from this software without specific prior 
//   written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS 
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL 
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ------------------------------------------------------------------------------------------

#ifndef TYPEK_H
#define TYPEK_H

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define TC_RANGE_ERR -99999.0
#define C_TO_F(x) ( 1.8 * x + 32.0 )
#define F_TO_C(x) ( ( x - 32.0 ) / 1.8 )

// ----------------- ITS-90 linearization of type K thermocouples
//
class TypeK {
  public:
    TypeK();
    double Temp_C( float mV );   // returns temperature (referenced to 0C) for mV
    double Temp_F( float mV );
    double Temp_C( float mV, float ambC );  // returns temperature referenced to ambC
    double Temp_F( float mV, float ambF );  // returns temperature referenced to ambF
    double mV_C ( float ambC );  // returns emf for ambient temperature
    double mV_F ( float ambF );
    boolean inrange_mV( float mV );
    boolean inrange_C( float ambC );
    boolean inrange_F( float ambF );
  private:
    // inverse coefficients
    static const double coeff_inv[10][3];
    static const float range_inv[2][3];
    static const int nranges_inv;
    static const int ncoeff_inv;
    static const float mv_min;
    static const float mv_max;
    static const float C_max;
    float F_max;
    static const float C_min;
    float F_min;

    // direct coefficients
    static const double coeff_dir[11][2];
    static const double range_dir[2][2];
    static const double a[3];  
};

#endif
