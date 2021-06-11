package main

import (
  "fmt"
  "sort"
)

type Item struct {
  id int
  value float64
  weight float64
}

func main() {
  var numOfItems int
  var knapsackWeight float64
  var items []Item

  fmt.Print("Enter number of items: ")
  fmt.Scanf("%d", &numOfItems)

  fmt.Print("Enter knapsack weight: ")
  fmt.Scanf("%f", &knapsackWeight)

  for i := 0; i<numOfItems; i++ {
    var weight float64
    var value float64
    fmt.Printf("Enter Item %d (weight value) : ", i+1)
    fmt.Scanf("%f %f", &weight, &value)
    items = append(items, Item{
      id: i+1,
      weight: weight,
      value: value,
    })
  }

  sort.Slice(items, func(i, j int) bool { return items[i].value/items[i].weight >= items[j].value/items[j].weight })

  // show the items selected
  fmt.Print("Selected Items: ")
  for _, item := range items {
    if knapsackWeight <= 0 {
      break
    }

    if item.weight <= knapsackWeight {
      fmt.Printf("%d ,", item.id)
      knapsackWeight -= item.weight
    } else {
      fmt.Printf("%f x %d", knapsackWeight/item.weight, item.id)
      break
    }
  }
  fmt.Println()
}
