#include <algorithm>
#include <iterator>
#include <vector>

using std::max;
using std::vector;

struct Event {
  int start, finish;
};

int FindMaxSimultaneousEvents(const vector<Event>& A) {
  struct Endpoint {
    int time;
    bool is_start;
  };
  
  //Builds an array of all endpoints.
  vector<Endpoint> E;
  for(const Event& event : A) {
    E.push_back({event.start, true});
    E.push_back({event.finish, false});
  }
  
  //Sorts the endpoint array according to the time, breaking ties
  //by putting start timese before end times.
  sort(begin(E), end(E), [](const Endpoint& a, const Endpoint& b) {
    //If times are equal, an endpoint that starts an interval comes first.
    return a.time != b.time ? a.time < b.time : (a.is_start && !b.is_start);
  });
  
  //Track the number of simultaneous events, and record the maximum
  //number of simultaneous events.
  int max_num_simultaneous_events = 0, num_simultaneous_events = 0;
  for(const Endpoint& endpoint : E) {
    if(endpoint.is_start) {
      ++num_simultaneous_events;
      max_num_simultaneous_events = 
        max(num_simultaneous_events, max_num_simultaneous_events);
    } else {
      --num_simultaneous_events;
    }
  }
  return max_num_simultaneous_events;
}
