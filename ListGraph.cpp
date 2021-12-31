#include "ListGraph.h"

ListGraph::ListGraph(size_t vertices_count):
    vertices(vertices_count){
}

ListGraph::ListGraph(const IGraph &graph) {
    for (int i = 0; i < graph.VerticesCount(); i++){
        vertices.push_back(graph.GetNextVertices(i));
    }
}

void ListGraph::AddEdge(int from, int to) {
    vertices[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return vertices[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (size_t start = 0; start < vertices.size(); start++) {
        for (size_t dest : vertices[start]) {
            if (dest == vertex) {
                result.push_back(start);
                break;
            }
        }
    }
    return result;
}

ListGraph::~ListGraph() {
}
