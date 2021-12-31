#include "ArcGraph.h"


ArcGraph::ArcGraph(size_t _vertices_count) :
    vertices_count(_vertices_count) {
}

ArcGraph::ArcGraph(const IGraph &graph) {
    vertices_count = graph.VerticesCount();
    for (size_t start = 0; start < vertices_count; start++) {
        std::vector<int> next_vert = graph.GetNextVertices(start);
        for (int dest: next_vert) {
            vertices.push_back(std::pair<int, int>(start, dest));
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    vertices.push_back(std::pair<int, int>(from, to));
}

int ArcGraph::VerticesCount() const {
    return vertices_count;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for(std::pair<int, int> edge : vertices){
        if (edge.first == vertex)
            result.push_back(edge.second);
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for(std::pair<int, int> edge : vertices){
        if (edge.second == vertex)
            result.push_back(edge.first);
    }
    return result;
}
