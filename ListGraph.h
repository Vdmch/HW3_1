#pragma once

#include "IGraph.h"

class ListGraph : public IGraph {
public:
    ListGraph(size_t vertices_count);
    ListGraph(const IGraph &graph);
    ~ListGraph() override;
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> vertices;
};
