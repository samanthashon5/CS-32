//
//  main.cpp
//  main
//
//  Created by Samantha Shon on 3/2/24.
//
#include <iostream>
#include <string>
#include <cassert>
#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
using namespace std;
int main()
{
// sample test code
PlaneFlight shortleg( "Howard", "LAX", "LAS", 49.00, 285 );
PlaneFlight longleg( "Howard", "LAS", "NYC", 399.00, 2800 );
PlaneFlight sample( "Sample", "Sample", "Sample", 0, 1 );
FrequentFlyerAccount account( "Howard" );
assert( shortleg.getFromCity( ) == "LAX" );
assert( shortleg.getToCity( ) == "LAS" );
assert( shortleg.getName( ) == "Howard" );
assert( std::to_string( shortleg.getCost( ) ) == "49.000000" );
assert( std::to_string( shortleg.getMileage( ) ) == "285.000000" );
// account balance starts at zero...
assert( std::to_string( account.getBalance( ) ) == "0.000000" );
assert( account.getName( ) == "Howard" );
assert( account.canEarnFreeFlight( 3300.00 ) == false );
// flights add to an account balance
assert( account.addFlightToAccount( shortleg ) == true ); // returns true
//because the names match
assert( account.addFlightToAccount( longleg ) == true ); // returns true
//because the names match
assert( std::to_string( account.getBalance( ) ) == "3085.000000" );
// free flights reduce an account balance
if (account.canEarnFreeFlight( 285 ))
{
assert( account.freeFlight( "LAS", "LAX", 285, sample ) == true );
// Howard earned a free flight...
assert( sample.getName( ) == "Howard" );
assert( std::to_string( sample.getCost( ) ) == "0.000000" );
assert( sample.getFromCity( ) == "LAS" );
assert( sample.getToCity( ) == "LAX" );
assert( std::to_string( sample.getMileage( ) ) == "285.000000" );
// account has been reduced for this free flight...
assert( std::to_string( account.getBalance( ) ) == "2800.000000" );
}
else
{
assert( false ); // there are enough miles in the account...
}
// non-matching names are ignored
PlaneFlight muffin( "Muffin", "LAX", "Doggie Heaven", 500, 500 );
assert( account.addFlightToAccount( muffin ) == false );
assert( std::to_string( account.getBalance( ) ) == "2800.000000" );
cout << "all tests passed!" << endl;
return( 0 );
}
