/**
 * Author: Lawry Sorenson
 * License: TBD
 * Source: TBD
 * Description: Generates all unique permutations / decreasing combinations in lexigraphical order.
 * Sort input in advance to get unique, ordered selections.
 * Usage:
 * string s="aabcc", ans(2, ' ');
 * comb(s, 2, ans, false, [](string\& s) { cout << s << endl; });
 */

#pragma once

#include<bits/stdc++.h>

template<typename F>
void perm(string& s, F lambda, int i = 0) {
    if (i==sz(s)) { lambda(s); return; }
    perm(s,lambda,i+1);
    rep(j,i+1,sz(s)) if (s[j]!=s[i])
        swap(s[i],s[j]),perm(s,lambda,i+1);
    rotate(s.begin()+i, s.begin()+i+1, s.end());
}

template<typename F>
void comb(string& s, int k, string& ans, bool replace, F lambda, int pj = -1) {
    if (!k--) { lambda(ans); return; }
    int sj=max(0,pj+!replace);
    rep(j,sj,sz(s)) if (j==sj || s[j]!=s[j-1])
        ans[k]=s[j],comb(s,k,ans,replace,lambda,j);
}
