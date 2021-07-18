
kthfind([A|L],K,A,I):-K is I.
kthfind([A|L],K,E,I):-J is I+1, kthfind(L,K,E,J).
kthfind([A|L],K,E):-kthfind([A|L],K,E,0).
