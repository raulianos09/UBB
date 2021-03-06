%minsert(L-list, E-element, R-resulted list)
%minsert(i,i,o)
minsert([], E, [E]).
minsert([H|T], E, [E, H|T]).
minsert([H|T], E, [H|Tr]):-
    minsert(T, E, Tr).

%perm(L-list, R - resulted list)
%perm(i,o)
perm([], []).
perm([H|T], R):-
    perm(T,RT),
    minsert(RT, H, R).

%comb(L-list, K-no of elems, R-resulted list)
%comb(i,i,o)
comb(_, 0, []).
comb([H|T], K, [H|Tr]):-
    K>0,
    K1 is K-1,
    comb(T,K1,Tr).
comb([_|T], K, R):-
    K>0,
    comb(T,K,R).

%arr(L-list, K-no of elems, R-resulted list)
%arr(i,i,o)
arr(L,K,R):-
    comb(L,K,R1),
    perm(R1,R).
