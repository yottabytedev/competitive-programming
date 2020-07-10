template<typename K, typename V>
std::vector<std::pair<K,V>> mapToVector(const std::unordered_map<K,V> &map)
{
    return std::vector<std::pair<K,V>>(map.begin(), map.end());
}
int divCount(int n) 
{ 
    // sieve method for prime calculation 
    bool hash[n + 1]; 
    memset(hash, true, sizeof(hash)); 
    for (int p = 2; p * p < n; p++) 
        if (hash[p] == true) 
            for (int i = p * 2; i < n; i += p) 
                hash[i] = false; 
  
    // Traversing through all prime numbers 
    int total = 1; 
    for (int p = 2; p <= n; p++) { 
        if (hash[p]) { 
  
            // calculate number of divisor 
            // with formula total div =  
            // (p1+1) * (p2+1) *.....* (pn+1) 
            // where n = (a1^p1)*(a2^p2)....  
            // *(an^pn) ai being prime divisor 
            // for n and pi are their respective  
            // power in factorization 
            int count = 0; 
            if (n % p == 0) { 
                while (n % p == 0) { 
                    n = n / p; 
                    count++; 
                } 
                total = total * (count + 1); 
            } 
        } 
    } 
    return total; 
} 
bool compare(vector<pair<long long int,int> > aaja,vector<pair<long long int,int> > chalaja)
{
    return aaja[0]>chalaja[0];
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector < long long int > g;
  int n1 = A.size();
  long long int i,j,pr,n;
    unordered_map<long long int,int> freq;
  for (i = 0; i < n1; i++) {
    for (j = i; j < n1; j++) {
      g.push_back(*max_element(A.begin() + i, A.begin() + j + 1));
    }
  }
    for(long long int const &i:g)
        freq[i]++;
    vector<pair<long long int,int> > f = mapToVector(freq);
  //product of divisors
  for (j = 0; j < f.size(); j++) {
    // pr = 1;
    // n = g[j];
    // for (i = 1; i <= n; i++) {
    //   if (n % i == 0) {
    //       pr *= i;
    //     }
    //   }
    f[j].first = (pow(f[j].first,divCount(f[j].first)/2) )% 1000000007;
  }
  // sort
  reverse(f.begin(), f.end(),compare);
  
  vector<long long int> x;
  for(i=0;i<B.size();i++)
  {
      n = B[i];
      j = 0;
      while(n)
      {
          n = n - f[j].second;
          j++;
      }
      x.push_back(f[j].first);
  }
  
  return x;
}
