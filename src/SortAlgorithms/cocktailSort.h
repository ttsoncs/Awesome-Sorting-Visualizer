#ifndef COCKTAIL_SORT_H
#define COCKTAIL_SORT_H

#include "../sortStrategy.h"
class CocktailSort : public SortStrategy {
  public:
    explicit CocktailSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Cocktail Sort");
    }

    ~CocktailSort() noexcept override = default;

    CocktailSort(const CocktailSort &other) = delete;

    CocktailSort &operator=(const CocktailSort &other) = delete;

    CocktailSort(CocktailSort &&other) noexcept = default;

    CocktailSort &operator=(CocktailSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        bool swapped{true};
        while (swapped) {
            swapped = false;
            for (auto i{0}; i < size - 1; ++i) {
                if (v[i].first > v[i + 1].first) {
                    Visualize::visualizeBar(v, i, "Cocktail Sort");
                    Visualize::visualizeBar(v, i + 1, "Cocktail Sort");
                    std::swap(v[i], v[i + 1]);
                    swapped = true;
                    Visualize::visualizeVector(v, "Cocktail Sort");
                }
            }
            if (!swapped) { break; }
            swapped = false;
            for (auto i{size - 1}; i > 0; --i) {
                if (v[i].first < v[i - 1].first) {
                    Visualize::visualizeBar(v, i, "Cocktail Sort");
                    Visualize::visualizeBar(v, i - 1, "Cocktail Sort");
                    std::swap(v[i], v[i - 1]);
                    swapped = true;
                    Visualize::visualizeVector(v, "Cocktail Sort");
                }
            }
        }
        Visualize::visualizeEnding(v, "Cocktail Sort");
    }
};

#endif