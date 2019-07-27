---
title: "Grafos"
---

# {{page.title}}

- Slides de Nico Lehmann sobre Grafos:
  - <http://campamento2015.progcomp.cl/material (revisar la parte Grafos)>
  - <http://campamento2016.progcomp.cl/material (revisar la parte Grafos)>
- Play list sobre Grafos: <https://www.youtube.com/playlist?list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j>
- Breadth First Search (BFS) & Depth First Search (DFS):
  - <https://www.youtube.com/watch?v=ImMnYq2zP4Y>
  - <https://www.youtube.com/watch?v=zaBhtODEL0w>
- Flood Fill: <https://en.wikipedia.org/wiki/Flood_fill>
- Articulation Points (aka Cut Vertices), Bridges (aka Cut Edges) and Biconnected Components (aka Blocks):
  - Graph Theory: 53. Cut-Vertices: <https://www.youtube.com/watch?v=BxAgmaLWaq4>
  - Graph Theory: 55. Bridges and Blocks: <https://www.youtube.com/watch?v=iGsxKUzW3cs>
  - Menger's Theorem: <https://www.youtube.com/watch?v=dUAeleBMRCQ>
    - <https://www.quora.com/How-can-I-prove-without-using-Mengers-theorem-that-any-two-vertices-of-a-2-connected-graph-lie-on-a-common-cycle>
  - Articulation Points Graph Algorithm: <https://www.youtube.com/watch?v=2kREIkF9UAs>
  - <http://web.iitd.ac.in/~bspanda/biconnectedMTL776.pdf>
  - <https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/>
  - <https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/>
  - Código de ejemplo: <https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Graphs/articulation-points%2Ccut-edges%2Cbiconnected-components.cpp>
  - <https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Graphs/diameter_of_tree.cpp>
- Dijkstra:
  - <https://www.youtube.com/watch?v=gdmfOwyQlcI>
  - <https://www-m9.ma.tum.de/graph-algorithms/spp-dijkstra/index_en.html>
  - <https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Graphs/Dijkstra.cpp>
- Minimum Spanning Tree:
  - Kruskal's Algorithm:
    - <https://www.youtube.com/watch?v=71UQH7Pr9kU>
    - <https://www.youtube.com/watch?v=fAuF0EuZVCk>
  - Prim's Algorithm:
    - <https://www.youtube.com/watch?v=cplfcGZmX7I>
    - <https://www.youtube.com/watch?v=oP2-8ysT3QQ>
  - Correcteness Proofs:
    - Proof of Cut Property: <https://www.youtube.com/watch?v=P7K7mG8QDVM>
    - Proof of Prim's MST algorithm using cut property: <https://www.youtube.com/watch?v=UfhUr5QzfiI>
    - Correctness of Kruskal's Algorithm: <https://www.youtube.com/watch?v=S9PIItOUyzA>
  - Example Code: <https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Graphs/MinimumSpanningTree.cpp>
- Topological Sort:
  - <https://www.youtube.com/watch?v=ddTC4Zovtbc>
  - <https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Graphs/TopoSort.cpp>

## Algoritmos de Arboles

- Trees (Árboles): <https://en.wikipedia.org/wiki/Tree_(graph_theory)>
- Diámetro de un árbol:
  - <http://cs.stackexchange.com/questions/22855/algorithm-to-find-diameter-of-a-tree-using-bfs-dfs-why-does-it-work>
- Lowest Common Ancestor (LCA):
  - General Overview of Methods:
    - <http://codeforces.com/blog/entry/16221 (skip to the LCA part)>
  - Sparse Tables and LCA: <https://www.youtube.com/watch?v=EKcQt-74bNw>
  - Method 1 (RECOMMENDED): Binary Lifting Method (aka jump pointers: <https://en.wikipedia.org/wiki/Level_ancestor_problem#Jump_pointer_algorithm>):
    - <http://codeforces.com/blog/entry/22325>
      - Note: as the post says, this method is very handy as it can be also used to compute querys over paths in Trees
    - <https://www.youtube.com/watch?v=kOfa6t8WnbI>
  - Method 2: Euler Tour + Range Minimun Query:
    - <https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/>
    - Sparse Table Algorithm Range Minimum Query: <https://www.youtube.com/watch?v=c5O7E_PDO4U>
  - Example Code of Both Methods:
    - <https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Graphs/LCA.cpp>
- Level Ancestor:
  - <https://en.wikipedia.org/wiki/Level_ancestor_problem>
  - <https://www.quora.com/Why-does-storing-log-N-pointers-work-in-the-jump-pointer-solution-of-the-level-ancestor-problem>
  - <https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Graphs/LA.cpp>
- Heavy-Light Decomposition:
  - <https://blog.anudeep2011.com/heavy-light-decomposition/>
  - <https://www.geeksforgeeks.org/heavy-light-decomposition-set-1-introduction/>
  - <http://codeforces.com/blog/entry/22072>

## Max Flow:

- Episode 33 - Maximum Flow Intuition: <https://www.youtube.com/watch?v=K1i-wP82Zdo>
- Cuándo se usa:
  - (MUY RECOMENDADO) Ejemplos de problemas usando flujo: <https://www.youtube.com/watch?v=nKcVc8XkFSA>
  - Maximum Bipartite Matching: <http://www.geeksforgeeks.org/maximum-bipartite-matching/>
- Ford-Fulkerson Algorithm:
  - <https://www.youtube.com/watch?v=Tl90tNtKvxs>
  - <https://www.youtube.com/watch?v=XPpmzulEmjA>
  - <https://www.youtube.com/watch?v=MczX0SM3I84>
  - <https://www.youtube.com/watch?v=GiN3jRdgxU4>
  - Intuición detrás del grafo residual: <https://cs.stackexchange.com/questions/55041/residual-graph-in-maximum-flow>
- Dinic Algorithm (RECOMENDADO):
  - <https://www.youtube.com/watch?v=uM06jHdIC70>
  - <http://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/15451-f14/www/lectures/lec11/dinic.pdf>
  - <http://theory.stanford.edu/~tim/w16/l/l2.pdf>
  - <https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Graphs/Dinic.cpp>

[Índice de recursos](resources)\\
[Index](../index)
