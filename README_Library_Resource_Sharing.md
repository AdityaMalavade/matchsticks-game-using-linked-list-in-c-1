# Library Resource-Sharing Network Using Adjacency Matrix

## 1. About the Project

The Library Resource-Sharing Network is a C++ project developed to represent and display direct resource-sharing connections between different library branches. It uses a **Graph** data structure represented through an **Adjacency Matrix**.

In this project, each library branch is represented as a vertex, while a direct resource-sharing connection between two branches is represented as an edge. The adjacency matrix uses `1` to indicate a direct connection and `0` to indicate that no direct connection exists.

The program displays the adjacency matrix and lists the direct connections between all library branches.

## 2. Features

### Basic Features

- **Library Branch Representation:** Represent six library branches using vertices A, B, C, D, E, and F.
- **Adjacency Matrix:** Store direct connections between branches in a two-dimensional array.
- **Display Matrix:** Print the complete adjacency matrix in a readable format.
- **Direct Connection Display:** Display the pairs of library branches that have a direct resource-sharing connection.
- **Duplicate Prevention:** Display each undirected connection only once.
- **Connection Count:** Calculate and display the total number of direct connections.

### Library Resource-Sharing Features

- **Resource Sharing:** Model direct connections used for sharing books, journals, research papers, and digital materials.
- **Branch Identification:** Assign a unique vertex label to each library branch.
- **Connection Checking:** Check whether two branches are directly connected by examining the matrix entry.
- **Expandable Model:** Add more library branches by updating the vertex count, branch names, and adjacency matrix.

## 3. Data Structure Used — Graph (Adjacency Matrix)

A graph consists of vertices and edges:

- **Vertex:** Represents a library branch.
- **Edge:** Represents a direct resource-sharing connection between two branches.
- **Adjacency Matrix:** A two-dimensional array used to represent connections between vertices.

### Library Branch Representation

| Vertex | Library Branch |
|---|---|
| A | Main Library |
| B | Science Library |
| C | Engineering Library |
| D | Medical Library |
| E | Digital Library |
| F | Research Library |

### Adjacency Matrix

`1` indicates a direct connection, and `0` indicates no direct connection.

| | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| **A** | 0 | 1 | 1 | 0 | 1 | 0 |
| **B** | 1 | 0 | 1 | 1 | 0 | 0 |
| **C** | 1 | 1 | 0 | 0 | 1 | 1 |
| **D** | 0 | 1 | 0 | 0 | 1 | 1 |
| **E** | 1 | 0 | 1 | 1 | 0 | 0 |
| **F** | 0 | 0 | 1 | 1 | 0 | 0 |

The graph is undirected, so the matrix is symmetric: if branch A is connected to branch B, branch B is also connected to branch A.

### Direct Connections Between Library Branches

1. Main Library — Science Library
2. Main Library — Engineering Library
3. Main Library — Digital Library
4. Science Library — Engineering Library
5. Science Library — Medical Library
6. Engineering Library — Digital Library
7. Engineering Library — Research Library
8. Medical Library — Digital Library
9. Medical Library — Research Library

**Total direct connections: 9**

## 4. Technologies Used

- C++
- Graph data structure
- Adjacency matrix
- Two-dimensional arrays
- Nested loops
- Conditional statements
- Strings
- Standard input/output

## 5. Applications

- Representing resource-sharing connections between library branches.
- Planning book and journal sharing networks.
- Modelling connections between digital library systems.
- Displaying direct links between departments or campus facilities.
- Learning graph representation using adjacency matrices.
- Educational mini-projects in Data Structures and Algorithms (DSA).

## 6. Conclusion

The Library Resource-Sharing Network project demonstrates how a graph can be represented using an adjacency matrix in C++. Six library branches are represented as vertices, and their direct resource-sharing connections are represented by edges.

The program displays the adjacency matrix and identifies all direct connections between library branches without displaying duplicate undirected connections. The given graph contains **9 direct connections**. This project demonstrates the practical use of graphs, two-dimensional arrays, nested loops, and conditional statements in C++.

## 7. Language

C++
