package main

import (
  "fmt"
  "sort"
)

type Activity struct {
  ID int
  endtime int
  starttime int
}

func main() {
  var activities []Activity
  var numOfActivities int
  fmt.Print("Enter number of activities: ")
  fmt.Scanf("%d", &numOfActivities)

  for i := 0; i<numOfActivities; i++ {
    var (
      starttime int
      endtime int
    )
    fmt.Printf("Activity %d (starttime, endtime) : ", i+1)
    fmt.Scanf("%d %d", &starttime, &endtime)
    if endtime < starttime {
      panic(fmt.Errorf("endtime < starttime"))
    }
    activities = append(activities, Activity{
      ID: i+1,
      endtime: endtime,
      starttime: starttime,
    })
  }

  // sort the activities according to their endtime (increasing)
  sort.Slice(activities, func(i, j int) bool {return activities[i].endtime <= activities[j].endtime})

  // print the compatible activities
  lastEndtime := 0
  fmt.Print("Selected activities: ")
  for _, activity := range activities {
    if activity.starttime > lastEndtime {
      fmt.Printf("%d, ", activity.ID)
      lastEndtime = activity.endtime
    }
  }
  fmt.Println()
}
