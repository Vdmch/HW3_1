#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t vertices_count) :
    vertices(vertices_count, std::vector<bool>(vertices_count, false)){
}

MatrixGraph::MatrixGraph(const IGraph &graph) :
    vertices(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)) {
    for (int i = 0; i < graph.VerticesCount(); i++) {
        for(int vert : graph.GetNextVertices(i)){
            vertices[i][vert] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    vertices[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (size_t dest = 0; dest < vertices[vertex].size(); dest++) {
        if (vertices[vertex][dest]) {
            result.push_back(dest);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for(size_t start = 0; start < vertices.size(); start++){
        if (vertices[start][vertex]){
            result.push_back(start);
        }
    }
    return result;
}
