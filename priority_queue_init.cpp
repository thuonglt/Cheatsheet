std::priority_queue<int, std::vector<int>, std::greater<int> > minAtTop ();
std::priority_queue<int, std::vector<int>, std::less<int> > maxAtTop ();

class mycomparison
{
  bool reverse;
public:
  mycomparison();
  bool operator() (const int& lhs, const int&rhs) const
  {
    return lhs < rhs;
  }
};

std::priority_queue<int,std::vector<int>,mycomparison> complexCompare();

