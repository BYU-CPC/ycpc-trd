/**
 * Author: Paul Pritchard
 * Date: 1987
 * License: UNKNOWN
 * Source: https://cp-algorithms.com/algebra/prime-sieve-linear.html
 * Description: 
 * Computes primes and smallest factors up to N exclusive.
 * lp[i] stores smallest prime divisor of 2<=i<N
 * pr is list of primes < N
 * Status: TBD
 * Time: O(N)
 */

#pragma once


const int N = 10000000;
vi lp(N), pr;
rep(i,2,N) {
    if (!lp[i]) lp[i]=i,pr.push_back(i);
    for (int p : pr) {
        if (i*p>=N || p>lp[i])break;
        lp[i*p]=p;
    }
}

