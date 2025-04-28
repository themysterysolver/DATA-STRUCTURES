### Disjoint set union
---
###### What is DSU?
- DSU (Disjoint Set Union) is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) sets.
- Main operations:
  - `find(x)` → Find the parent (leader) of x.
  - `union(x, y)` → Join two sets if they are different.
- We also use:
  - ***Path compression*** → While finding, make nodes point directly to their leader for faster future finds.
  - ***Union by rank/size*** → While joining, attach smaller trees under larger ones to keep trees shallow.
