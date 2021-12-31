#include "SetGraph.h"

SetGraph::SetGraph(size_t vertices_count) :
    vertices(vertices_count){
}

SetGraph::SetGraph(const IGraph &graph) :
    vertices(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); i++) {
        std::vector<int> sel_vertices = graph.GetNextVertices(i);
        for (int new_vert : sel_vertices) {
            vertices[i].insert(new_vert);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    vertices[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int vert : vertices[vertex]) {
        result.push_back(vert);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (size_t start = 0; start < vertices.size(); start++)
        for (int dest : vertices[start]) {
            if (dest == vertex)
                result.push_back(start);
        }
    return result;
}
