/**
 * @file main.cpp
 * @brief This is a test of CMake, doxygen, and GitHub.
 * @details This is the long brief at the top of main.cpp. I used code from the book and used this website for their print function and to figure out how to work this guys code https://www.programiz.com/dsa/graph-adjacency-matrix, an additional website I used to understand the concept better: https://www.softwaretestinghelp.com/graph-implementation-cpp/
 * @author Seth McNeill
 * @date 1/28/2021
 * 
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class AdjacencyMatrix {
protected:
	int n;
	bool **MatrixChecker;
    
public:
    AdjacencyMatrix(int Size) {
        n = Size;
        MatrixChecker = new bool*[n];
        for (int i = 0; i < n; i++)
            MatrixChecker[i] = new bool[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                MatrixChecker[i][j] = false;
    };
    

	void addEdge(int i, int j) {
		MatrixChecker[i][j] = true;
	}


	void removeEdge(int i, int j) {
		MatrixChecker[i][j] = false;
	}


	bool hasEdge(int i, int j) {
		return MatrixChecker[i][j];
	}


	vector<int> outEdges(int i) {
        vector<int> outEdges;
		for (int j = 0; j < n; j++)
			if (MatrixChecker[i][j]) outEdges.push_back(j);
        return outEdges;
	}


	vector<int> inEdges(int i) {
        vector<int> inEdges;
		for (int j = 0; j < n; j++)
			if (MatrixChecker[j][i]) inEdges.push_back(j);
        return inEdges;
	}

	int nVertices() {
		return n;
	}

    /**
     * This code comes almost line for line from here: https://www.programiz.com/dsa/graph-adjacency-matrix
     */
    void printGraph() {
    cout << "T : ";
    for (int i = 1; i < n; i++) {
      cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      cout << i << " : ";
      for (int j = 0; j < n; j++)
        cout << MatrixChecker[i][j] << " ";
      cout << endl;
        }
    cout << endl;
    }

};

//void bfs(AdjacencyMatrix &g, int r) {
  //bool *seen = new bool[g.nVertices()];
  //seen[r] = true;
  //while (q.size() > 0) {
    //int i = q.remove();
    //vector<int> Edges = g.outEdges();
    //for (int k = 0; k < edges.size(); k++) {
     //int j = edges.get(k);
     // if (!seen[j]) {
        //q.add(j);
       // seen[j] = true;
    //  }
  //  }
 // }
 // delete[] seen;
//}

//void dfs2(AdjacencyMatrix &g, int r) {
 // char *c = new char[g.nVertices()];
 // vector<int> s;
 // for (int j = 0; j < g.nVertices(); j++){ 
  //      s.push_back(j);
    //}
 // int L = g.nVertices();
//for (int j = 0; j < L; j++){ 
   // if (c[j] == white) {
  //    c[j] = grey;
   //   ArrayStack<int> edges;
  //    vector<int> hi = g.outEdges(i);
   //   for (int k = 0; k < edges.size(); k++)
    //    s.push_back(edges.get(k));
   // }
  //}
 // delete[] c;
//}

int main(){
    AdjacencyMatrix Test(12);
    Test.addEdge(0,1);
	Test.addEdge(1,0);
	Test.addEdge(1,2);
	Test.addEdge(2,1);
	Test.addEdge(2,3);
	Test.addEdge(3,2);
	Test.addEdge(3,7);
	Test.addEdge(7,3);
	Test.addEdge(0,4);
	Test.addEdge(4,0);
	Test.addEdge(4,5);
	Test.addEdge(5,4);
	Test.addEdge(1,5);
	Test.addEdge(5,1);
	Test.addEdge(1,6);
	Test.addEdge(6,1);
	Test.addEdge(2,5);
	Test.addEdge(6,7);
	Test.addEdge(7,6);
	Test.addEdge(4,8);
	Test.addEdge(8,4);
	Test.addEdge(8,9);
	Test.addEdge(9,8);
	Test.addEdge(9,10);
	Test.addEdge(10,9);
	Test.addEdge(10,11);
	Test.addEdge(11,10);
	Test.addEdge(11,7);
	Test.addEdge(7,11);
	Test.printGraph();
}	
