#include<bits/stdc++.h>
using namespace std;
 typedef pair<int,int> pii;
 typedef pair<char,char> pcc;
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<ull> vull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef tuple<int,int,int> tiii;
#define rkmod 1125899906842597LL
#define mod1 1000000007LL
#define mod 1000000007LL
#define mod2 1000000007LL
#define mod3 1000000009LL
#define mx9 1000000000LL
#define mx10 10000000000LL
#define mx5 100000
#define mx8 100000000LL
#define mx7 10000000LL
#define mx6 1000000LL
#define mx6_5 5000000
#define last 4444444444
 #define f first
 #define s second
 #define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define reprev(i,a,b) for(ll i=(a);i>=(b);i--)
 #define repi(i,a,b) for(int i=(a);i<=(b);i++)
#define reprevi(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define x first
#define y second
//#define PI 3.14159265
const long double PI = 2*acos(0.0);
const int stdLength = 25;
const ll max_number = 1048575;
typedef vector<bool> vb;
void print(vb &a)
{
 
    for(bool i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vi &a)
{
 
    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vc &a)
{
 
    for(char i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vll &a)
{
 
    for(ll i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vector<vi> &a)
{
    for(vi i:a)
    {
        print(i);
    }
    cout<<"\n";
}
void print(vector<vll> &a)
{
    for(vll i:a)
    {
        print(i);
    }
    cout<<"\n";
}
void print(vector<double> &a)
{
 
    for(double i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vector<long double> &a)
{
 
    for(long double i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vector<pll> &a)
{
 
    for(pll i:a)
    {
        cout<<i.f<<" "<<i.s<<"\n";
    }
    cout<<"\n";
}
void print(deque<pll> &a)
{
 
    for(pll i:a)
    {
        cout<<i.f<<" "<<i.s<<"\n";
    }
    cout<<"\n";
}
ll dist_sq(pll a,pll b)
{
    return ((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
}
 
ll po(ll a,ll b)
{
    if(b<=0)
        return 1;
    else if(b==1)
        return a;
 
    ll vl = po((a*a),b/2);
    if(b%2==0)
        return vl;
    else
        return (vl)*a;
}
 
ll pomod(ll a,ll b)
{
    a= a%mod;
    if(b<=0)
        return 1%mod;
    else if(b==1)
        return a%mod;
 
    ll vl = pomod((a*a)%mod,b/2);
    vl = vl%mod;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mod;
}

ll pomod(ll a,ll b,ll mo)
{
    a= a%mo;
    if(b<=0)
        return 1%mo;
    else if(b==1)
        return a%mo;
 
    ll vl = pomod((a*a)%mo,b/2);
    vl = vl%mo;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mo;
}
ll factmod(ll n, ll mo)
{
    ll val=n;
    ll ans =1;
    while(val>=1)
    {
        ans = (ans*val)%mo;
        val--;
    }
    
    return ans;
}
ll inv(ll a,ll mo)
{
    return pomod(a,mo-2,mo);
}

ll combinationMod(ll n, ll i)
{
    ll ans = 1;
    ans = (ans * factmod(n,mod))%mod;
    ll invVal =  (inv(factmod(i,mod),mod)%mod * inv(factmod(n-i,mod),mod)%mod)%mod;
    ans = (ans * invVal)%mod;
    return ans;
}
ll greatestCommonDivisor(ll a, ll b){
    if(b>a){
        return greatestCommonDivisor(b,a);
    }
    if(b==0){
        return a;
    }
    
    if(a%b==0){
        return b;
    } else{
        return greatestCommonDivisor(b,a%b);
    }
}
ll greatestCommonDivisor( const vll &numList, int st, int en){
    assert(st>=0 and st<(int)numList.size());
    assert(en>=0 and en<(int)numList.size());
    if(st>en){
        return 0;
    } else if(st==en){
        return numList[st];
    } else if(en==st+1){
        return greatestCommonDivisor(numList[st],numList[st+1]);
    } else{
        return greatestCommonDivisor(numList[st],greatestCommonDivisor(numList,st+1,en));
    }
}
ll greatestCommonDivisor( const vll &numList){
    if(numList.size()==0){
        return 0;
    }
    int st = 0;
    int en = numList.size();
    en--;
    return greatestCommonDivisor(numList,st,en);
}
vector<vll> preComputeCombinationMod(int n)
{
    vector<vll> comb(n+1,vll(n+1,0));
    comb[0][0]=1;
    rep(i,1,n)
    {
        comb[i][0] = 1;
        comb[0][i] = 0;
    }
    
    rep(i,1,n)
    {
        rep(j,1,i)
        {
            comb[i][j] = (comb[i-1][j-1]%mod + comb[i-1][j]%mod)%mod;
        }
    }
    
    return comb;
}
ll floorlog2(ll n)
{
    ll h = 0;
    ll p = 1;
    while(p<=n)
    {
        h++;
        p*=2;
    }
    
    return h-1;
}
ll floorlog2(ll n,ll b)
{
    ll h = 0;
    ll p = 1;
    while(p<=n)
    {
        h++;
        p*=b;
    }
    
    return h-1;
}

class TrieXORSetNode {
    private:
    vector<TrieXORSetNode *> children;
    bool this_inserted = false;
    set<int> indexSet;
    ll currentVal = 0;
    
    public:
    /**
     * Initialize Trie here. */
     TrieXORSetNode() {
         children.resize(2,NULL);
         this_inserted = false;
     }
     /** Inserts word into Trie after converting it to a string of '0's and '1's
      * Arguments:
      * ll word: the word to be this_inserted 
      * int node_index: the node_index it refers to */
     void insertWord (ll word, int node_index, set<TrieXORSetNode *> & allowedTrieNodes){
         assert(word>=0 and word<= max_number);
         string binaryRepresentation = bitset<stdLength> (word).to_string();
         cout<<"insertWord word: "<<word<<"\n";
         cout<<"binaryRepresentation: "<<binaryRepresentation<<"\n\n";
         insertWord(binaryRepresentation, node_index, allowedTrieNodes);
     }
      /** Inserts word into Trie.
      * Arguments:
      * word: the word to be this_inserted
      * int node_index: the node_index it refers to */
      void insertWord(string word, int node_index, set<TrieXORSetNode *> & allowedTrieNodes) {
          auto cur = this;
          assert(word.length() == stdLength);
          
          for(auto elem: word){
              assert(elem == '0' or elem=='1');
              int child = elem - '0';
              cur->indexSet.insert(node_index);
              allowedTrieNodes.insert(cur);
              if(cur->children[child]){
                  cur = cur->children[child];
              } else{
                  cur ->children[child] = new TrieXORSetNode();
                  cur = cur ->children[child]; 
              }
          }
          allowedTrieNodes.insert(cur);
          cur->this_inserted = true;
          cur ->indexSet.insert(node_index);
          ll valFromWord = stoll(word, nullptr, 2);
          cur->currentVal = valFromWord;
      }
      
     /** Inserts word into Trie after converting it to a string of '0's and '1's
      * Arguments:
      * ll word: the word to be this_inserted 
      * int node_index: the node_index it refers to */
     void insertWord (ll word, int node_index){
         assert(word>=0 and word<= max_number);
         string binaryRepresentation = bitset<stdLength> (word).to_string();
         cout<<"insertWord word: "<<word<<"\n";
         cout<<"binaryRepresentation: "<<binaryRepresentation<<"\n\n";
         insertWord(binaryRepresentation, node_index);
     }
     /** Inserts word into Trie.
      * Arguments:
      * word: the word to be this_inserted
      * int node_index: the node_index it refers to */
      void insertWord(string word, int node_index) {
          auto cur = this;
          assert(word.length() == stdLength);
          
          for(auto elem: word){
              assert(elem == '0' or elem=='1');
              int child = elem - '0';
              cur->indexSet.insert(node_index);
              if(cur->children[child]){
                  cur = cur->children[child];
              } else{
                  cur ->children[child] = new TrieXORSetNode();
                  cur = cur ->children[child]; 
              }
          }
          cur->this_inserted = true;
          cur ->indexSet.insert(node_index);
          ll valFromWord = stoll(word, nullptr, 2);
          cur->currentVal = valFromWord;
      }
      /**
       * Search Trie for word which is a binary string
       */
      bool searchTrie(string word){
          auto cur = this;
          assert(word.length() == stdLength);

          for(auto elem: word) {
              assert(elem == '0' or elem=='1');
              int child = elem - '0';
              if(cur->children[child] ==NULL){
                  return false;
              }
              cur = cur->children[child];
          }
          return cur->this_inserted;
      }
      /**
       * Search Trie for word which is an integer
       */
      bool searchTrie(ll word) {
        assert(word>=0 and word<= max_number);
        string binaryRepresentation = bitset<stdLength> (word).to_string();
        cout<<"searchTrie word: "<<word<<"\n";
        cout<<"binaryRepresentation: "<<binaryRepresentation<<"\n\n";
        return searchTrie(binaryRepresentation);
      }
      /**
       * find max xor amongst numbers in Trie
       */
      ll getMaxXOR(string word) {
          assert(word.length() == stdLength);
          auto cur = this;
          
          for(auto elem: word){
              assert(elem == '0' or elem=='1');
              int childIndex = elem-'0';
              int oppChildIndex = (1-childIndex);
              assert((cur->children[childIndex] or cur>children[oppChildIndex]) && "Undefined XOR path. NULL found");
              cur = (cur->children[oppChildIndex])?cur->children[oppChildIndex]:cur->children[childIndex];
          }
          ll valFromWord = stoll(word, nullptr, 2);
          ll bestXOR = valFromWord ^ cur->currentVal;
          return bestXOR;
       }
       /**
       * find max xor amongst all  numbers in Trie
       * ll word
       */
      ll getMaxXOR(ll word) {
            assert(word>=0 and word<= max_number);
            string binaryRepresentation = bitset<stdLength> (word).to_string();
            cout<<"getMaxXOR word: "<<word<<"\n";
            cout<<"binaryRepresentation: "<<binaryRepresentation<<"\n\n";
            return getMaxXOR(binaryRepresentation);
       }
       /**
       * find max xor amongst numbers in Trie
       * restricted to allowedTrieNodes
       */
      ll getMaxXOR(string word, const set<TrieXORSetNode *> &allowedTrieNodes) {
          assert(word.length() == stdLength);
          auto cur = this;
          
          for(auto elem: word){
              assert(elem == '0' or elem=='1');
              int childIndex = elem-'0';
              int oppChildIndex = (1-childIndex);
              
              if(cur->children[oppChildIndex]!=NULL and allowedTrieNodes.count(cur->children[oppChildIndex])!=0){
                  cur = cur->children[oppChildIndex];
              } else if(cur->children[childIndex]!=NULL and allowedTrieNodes.count(cur->children[childIndex])!=0){
                  cur = cur->children[childIndex];
              } else{
                  assert(false && "No suitable XOR path found");
              }
          }
          ll valFromWord = stoll(word, nullptr, 2);
          ll bestXOR = valFromWord ^ (cur->currentVal);
          return bestXOR;
       }
       /**
       * find max xor amongst all  numbers in Trie
       * restricted to allowedTrieNodes
       * ll word
       */
      ll getMaxXOR(ll word, const set<TrieXORSetNode*> &allowedTrieNodes) {
            assert(word>=0 and word<= max_number);
            string binaryRepresentation = bitset<stdLength> (word).to_string();
            cout<<"getMaxXOR restricted word: "<<word<<"\n";
            cout<<"binaryRepresentation: "<<binaryRepresentation<<"\n\n";
            return getMaxXOR(binaryRepresentation, allowedTrieNodes);
       }
};
class TrieXOR {
    private:
    vector<set<TrieXORSetNode*> > allowedTrieNodesVec;
    TrieXORSetNode root;
    public:
    TrieXOR(){
        allowedTrieNodesVec = vector<set<TrieXORSetNode*>>(2*mx5 +1);
    }
    
    TrieXOR(int n) {
        allowedTrieNodesVec = vector<set<TrieXORSetNode* > >(n+1);
    }
    
    /** Inserts word into Trie after converting it to a string of '0's and '1's
      * Arguments:
      * ll word: the word to be this_inserted 
      * int node_index: the node_index it refers to */
    void insertWord (ll word, int node_index){
         root.insertWord(word, node_index, allowedTrieNodesVec[node_index]);
     }
     
    /**
      * find max xor amongst all  numbers in Trie
      * restricted to allowedTrieNodesVec[node_index]
      * ll word
      */
    ll getMaxXOR(ll word, int node_index) {
        return root.getMaxXOR(word, allowedTrieNodesVec[node_index]);
     }
     /**
      * find max xor amongst all  numbers in Trie
      * ll word
      */
    ll getMaxXOR(ll word) {
        return root.getMaxXOR(word);
     }
     
    /**
     * search trie for word
     */
    bool searchTrie(ll word) {
        return root.searchTrie(word);
    } 
};
class Trie {
    private:
    vector<Trie*> children;
    bool this_inserted = false;
public:
    /** Initialize your data structure here. */
    Trie() {
        children.resize(26,NULL);
        this_inserted = false;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                cur->children[ind] = new Trie();
                
            }
            cur = cur->children[ind];
        }
        
        cur->this_inserted = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                return false;
            }        
                cur = cur->children[ind];
        }
        
        
        return cur->this_inserted;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        string word = prefix ;
        
      Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                return false;
            }        
                cur = cur->children[ind];
        }
        
        
        return true;
    }
};

class FenwickTree
{
    public:
    vll BIT;
    
    FenwickTree(int n)
    {
        BIT.resize(n+1,0);
    }
    FenwickTree(vll a)
    {
        int n = a.size();
        
        BIT.resize(n+1,0);
        
        rep(i,0,n-1)
        {
            update(i+1,a[i]);
        }
    }
    FenwickTree(vi a)
    {
        vll b(a.begin(),a.end());
        
        int n = b.size();
        
        BIT.resize(n+1,0);
        
        rep(i,0,n-1)
        {
            update(i+1,b[i]);
        }
    }
    
    void update(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        int x = ind;
        int sz = BIT.size();
        
        while(x<sz)
        {
            BIT[x]+=val;
            x += (x&-x);
        }
    }
    
    void set(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        ll currentVal = query(ind,ind);
        update(ind,val-currentVal);
    }
    ll query(int l, int r)
    {   
        assert(0<=l and r<BIT.size());
        
        if(r<l)
        {
            return 0;
        }
        else
            return prefQuery(r) - prefQuery(l-1);
    }
    ll prefQuery(int ind)
    {   
        assert(0<=ind and ind<BIT.size());
        int x = ind;
        ll sum = 0;
        while(x>0)
        {
            sum+=BIT[x];
            x-=(x&-x);
        }
        
        return sum;
    }
};
vll getPrimes(ll highestNum){
    
    vb isPrime(highestNum+5,true);
    vll primes;
    rep(i,2,highestNum){
        if(isPrime[i])
        {   primes.push_back(i);
            ll j = i;
            while(j*i<=highestNum){
                isPrime[j*i]=false;
                j++;
            }
        }
    }
    return primes;
}
ll getMultiplicity(ll num, ll prime){
    ll mult = 0;
    while(num%prime==0){
        mult+=1;
        num/=prime;
    }
    return mult;
}
vll getPrimeFactorization(ll num, vll &primes){
    int sz = primes.size();
    vll multcities(sz,0);
    
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return multcities;
        else
        {
            multcities[i] = getMultiplicity(num,prime);
            ll di = po(prime,multcities[i]);
            num = num/di;
        }
    }
    return multcities;
}

map<ll,ll> getMapPrimeFactorization(ll num, vll &primes){
    int sz = primes.size();
    map<ll,ll> primeFac;
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return primeFac;
        else
        {
            primeFac[prime] = getMultiplicity(num,prime);
            ll di = po(prime,primeFac[prime]);
            num = num/di;
        }
    }
    return primeFac;
}
vpll getListPrimeFactorization(ll num, vll &primes){
    int sz = primes.size();
    vpll primeFac;
    
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return primeFac;
        else
        {
            ll mult = getMultiplicity(num,prime);
            ll di = po(prime,mult);
            num = num/di;
        
            if(mult>0){
                primeFac.push_back(make_pair(prime,mult));
            }
        }
    }
    return primeFac;
}
vi compute_z(string s)
{
    int n = s.length();
    vi z(n,0);
    int l=0,r=0;
    z[0]=n;
    rep(i,1,n-1)
    {
        if(r<i)
        {
            l=r=i;
            int j = 0;
            if(s[0]!=s[i])
            {
                continue;
            }
            
            while(j<n and s[j] == s[i+j])
            {
                j++;
            }
            r = i+j-1;
            z[i] = r-i+1;
        }
        else
        {
            int beta = r-i+1;
            int k = i-l;
            
            if(z[k]<beta)
            {   
                
                z[i]=z[k];
              
            }
            else
            {
                int j = 0;
                l = i;
                while(r<n and s[r]==s[r-l])
                {   
                    r+=1;
                }
                r-=1;
                
                z[i] = r-i+1;
                
                
            }
        }
    }
    
    return z;
}

vi getOccurences(string s, string t){
    
     string comb = t + "$" + s;
    
     auto z_vals = compute_z(comb);
     
     int n = s.size();
     int t_sz = t.size();
 
     vi occ;
    
     rep(i,0,n-1)
     {
         if(z_vals[t_sz + 1 +  i]==t_sz){
             occ.push_back(i);
         }
     }
     return occ;
}

class DSU{
    private:
    vi parent;
    vi size;
    public:
    DSU(int n){
        parent.resize(n+5,0);
        size.resize(n+5,0);
        rep(i,1,n){
            parent[i]=i;
            size[i] = 1;
        }
    }
    vi getParents(){
        return parent;
    }
     vi getSizes(){
        return size;
    }
    int getRoot(int node){
       int par = parent[node];
       if(parent[par] == par){
           return par;
       }
       
       int root = getRoot(par);
       
       parent[node] = root;
       
       return root;
    }
    
    bool checkSame(int a, int b){
        return getRoot(a)==getRoot(b);
    }
    
    void connectNodes(int a, int b){
        int root1 = getRoot(a);
        int root2 = getRoot(b);
        
        if(size[root1] < size[root2]){
            swap(root1,root2);
        }
        
        parent[root2] = root1;
        size[root1] += size[root2];
    }
};

class SegmentTreeNode{
    private:
    
    ll total;
    ll pendingUpdate;
    
   
    public:
    int start,end;
    
    SegmentTreeNode(): total(0), start(-1),end(-1),pendingUpdate(0){} 
    
    void assignLeaf(ll value, int start, int end){
        total = value;
        this->start = start;
        this->end = end;
    }
    void merge(SegmentTreeNode &left, SegmentTreeNode&right){
        this->start = left.start;
        this->end = right.end;
        ll leftTotal = left.getValue();
        ll rightTotal = right.getValue();
        
        if(left.ifPendingUpdate()){
            leftTotal += left.getSegmentSize() * left.getPendingUpdate();
        }
        
        if(right.ifPendingUpdate()){
            rightTotal += right.getSegmentSize() * right.getPendingUpdate();
        }
        this->total = leftTotal + rightTotal;
        
    }
    ll getValue(){
        return total;
    }
    
    ll getPendingUpdate(){
        return pendingUpdate;
    }
    bool ifPendingUpdate(){
        return pendingUpdate!=0;
    }
    
    void applyPendingUpdate(){
        this->total += (this->pendingUpdate) * (this->getSegmentSize());
        this->pendingUpdate = 0;
    }
    
    void addUpdate(ll val){
        this->pendingUpdate += val;
    }
    
    int getSegmentSize(){
        return (end-start + 1);
    }
};

class SegmentTree{
   
    
    public:
    int N;
    SegmentTree(vll &arr){
        
        this->N = arr.size();
        this-> treeSize = getSegmentTreeSize(this->N);
        //cout<<"N treeSize:" <<N<<" "<<treeSize<<"\n";
        nodes.resize(this->treeSize);
        
        this->buildTree(arr,1,0,N-1);
    }
    
     void updateRange(int startPos, int endPos, ll val){
         //flip all coins in [startPos,endPos]
         updateRange(1,startPos,endPos,val);
     }
    ll getValue(int startPos, int endPos){
        auto res = getValue(1,startPos,endPos);
        return res.getValue();
    }
    private:
     vector<SegmentTreeNode> nodes;
     
     int treeSize;
     
     
     void buildTree(vll &arr,int stIndex, int left, int right){
         if(left==right){
             this->nodes[stIndex].assignLeaf(arr[left],left,right);
             return;
         } 
         
         int mid = (left+right)/2;
         int leftIndex = 2*stIndex,rightIndex = leftIndex+1;
         
         buildTree(arr,leftIndex,left,mid);
         buildTree(arr,rightIndex,mid+1,right);
         
         nodes[stIndex].merge(nodes[leftIndex],nodes[rightIndex]);
     }
     
    void updateRange(int stIndex, int startPos, int endPos, ll val){
        if(startPos == nodes[stIndex].start and endPos == nodes[stIndex].end){
            nodes[stIndex].addUpdate(val);
            return;
        }
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end)/2;
        int leftChildIndex = 2*stIndex, rightChildIndex = leftChildIndex + 1;
        
        if(endPos<=mid){
            updateRange(leftChildIndex,startPos,endPos,val);
        }else if(startPos>mid){
            updateRange(rightChildIndex,startPos,endPos,val);
        }else{
            updateRange(leftChildIndex,startPos,mid,val);
            updateRange(rightChildIndex,mid+1,endPos,val);
        }
        
        nodes[stIndex].merge(nodes[leftChildIndex],nodes[rightChildIndex]);
    }
    
    SegmentTreeNode getValue(int stIndex,int startPos, int endPos){
        if(startPos == nodes[stIndex].start and endPos == nodes[stIndex].end){
            auto result = nodes[stIndex];
            if(result.ifPendingUpdate())
                result.applyPendingUpdate();
                
            return result;
        }
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end)/2;
        int leftChildIndex = 2*stIndex, rightChildIndex = leftChildIndex + 1;
        
        SegmentTreeNode result;
        
        if(endPos<=mid){
            result = getValue(leftChildIndex,startPos,endPos);
        }else if(startPos>mid){
            result = getValue(rightChildIndex,startPos,endPos);
        }else{
            auto leftResult = getValue(leftChildIndex,startPos,mid);
            auto rightResult = getValue(rightChildIndex,mid+1,endPos);
            
            result.merge(leftResult,rightResult);
        }
        
        if(nodes[stIndex].ifPendingUpdate()){
            result.addUpdate(nodes[stIndex].getPendingUpdate());
            result.applyPendingUpdate();
        }
        
        return result;
    }
     int getSegmentTreeSize(int N){
         int x = 1;
         while(x<N){
             x = x*2;
         }
         return x*2;
     }
};



// pair<vll, vll> preComputeAnsDigits(ll highestNumOfDigits){
//     vector<vll> ansByDigit(10, vll (highestNumOfDigits+1,0LL));
//     vll ansDigit(highestNumOfDigits+1,0LL);
//     vll numsDigits(highestNumOfDigits+1,0LL);
    
//     ansDigits[0]=0LL;
//     numsDigits[0]=1LL;
    
//     rep(i,1,highestNumOfDigits){
//         numsDigits[i] = (numsDigits[i-1]*10LL)%mod;
//         rep(digit,0,9){
//             ll prevVal = ans
            
//             ll numsStartingWithDigit = (i>=2)?numsDigits[i-2]:1LL;
//             numsStartingWithDigit = (numsStartingWithDigit*(digit))%mod;
            
//             ansByDigit[digit][i] = ((digit *numsDigits[i-1])%mod * (numsDigits[i-1]))%mod;
//             ansByDigit[digit][i] = (ansByDigit[digit][i]%mod + ansDigit[i-1]%mod +
//         }
//     }
// }
const int DEBUG = true;
vll preComputedNumsDigits(mx5+5,0LL);
ll computeNumsDigits(int numDigits){
    ll finalNums = preComputedNumsDigits[numDigits];
    if(finalNums)
        return finalNums%mod;
    finalNums = pomod(10LL, numDigits,mod);
    preComputedNumsDigits[numDigits]=finalNums%mod;
    return finalNums%mod;
}


vector<vll> dp(mx5+5,vll(10,-1LL));
ll computeAnsDigits(int numDigits = 0, int disallowedVal=0){
    
    if(numDigits==0){
        return 0LL;
    }
    auto seenVal = mp(numDigits, disallowedVal);
    
    if(dp[seenVal.first][seenVal.second]>=0){
        return dp[seenVal.first][seenVal.second]%mod;
    }
    
    ll finalAns= 0LL;
    ll thisCoeff = pomod(10LL, numDigits-1,mod)%mod;
    
    ll nextNums = computeNumsDigits(numDigits-1)%mod;
    ll thisVal = ((45LL-disallowedVal)*thisCoeff)%mod;
    finalAns = (finalAns%mod + (thisVal*nextNums)%mod)%mod;
    rep(digit, 0, 9){
        ll nextVal = computeAnsDigits(numDigits-1, digit)%mod;
        finalAns =(finalAns%mod + nextVal)%mod;
    }
    dp[seenVal.first][seenVal.second] = finalAns%mod;
    return finalAns%mod;
}



unordered_map<int,ll> preComputedNums;
ll computeNums(const string &R, int ind=0){
    if(R.empty() or ind>=R.size()){
        return 1LL;
    }
    if(preComputedNums.count(ind))
        return preComputedNums[ind]%mod;
    
    int MSD = R[ind] - '0';
    int numDigits = R.size()-ind;
    
    ll finalAns = 0LL;

    finalAns = (finalAns%mod + ((MSD)*computeNumsDigits(numDigits-1))%mod)%mod;
    
    finalAns = (finalAns%mod + (computeNums(R,ind+1))%mod)%mod;
    
    preComputedNums[ind] = finalAns%mod;
    
    return finalAns%mod;
}

map<pii,ll> preComputedAns;
ll computeAns(const string &R, int ind=0, int disallowedVal = 0){
    if(R.empty() or ind>=R.size()){
        return 0LL;
    }
    
    auto seenVal = mp(ind,disallowedVal);
    
    if(preComputedAns.count(seenVal)){
        return preComputedAns[seenVal]%mod;
    }
    int MSD = R[ind] - '0';
    int numDigits = R.size()-ind;
    
    ll finalAns = 0LL;
    ll thisCoeff = computeNumsDigits(numDigits-1)%mod;
    ll nextNums = computeNums(R,ind+1)%mod;
    ll nextNumsAll = computeNumsDigits(numDigits-1)%mod;
    
    rep(digit, 0 , MSD){
        
        ll nextVal = (digit<MSD)?computeAnsDigits(numDigits-1, digit):computeAns(R, ind+1,digit);
        finalAns =(finalAns%mod + nextVal)%mod;
        if(digit!=disallowedVal){
            ll thisVal = (digit*thisCoeff)%mod;
            ll numsMultiplier = (digit<MSD)?nextNumsAll:nextNums;
            finalAns = (finalAns%mod + (thisVal*numsMultiplier)%mod)%mod;
        }
        
    }
    preComputedAns[seenVal]=finalAns%mod;
    return finalAns%mod;
}
string subtractOne(const string &L){
    int ind = L.size();
    ind --;
    string answer = L;
    while(ind>= 0 and answer[ind]=='0'){
        answer[ind]='9';
        ind--;
    }
    
    if(ind>=0){
        answer[ind]-=1;
    }
    
    return answer;
}
void clearState(){
    preComputedNums.clear();
    preComputedAns.clear();
    // if(DEBUG){
    //     cout<<"Sizes: "<<preComputedAns.size()<<" "<<preComputedNums.size()<<"\n";
    // }
}
ll getAnswer(const string &L, const string &R){
    string minusOne = subtractOne(L);
    // if(DEBUG){
    //     cout<<"L minus One: "<<minusOne<<"\n\n";
    // }
    
    clearState();
    ll rightAns = computeAns(R);
    clearState();
    ll leftAns = computeAns(minusOne);
    return (rightAns - leftAns + mod)%mod;
}
void testOutput(ll hi=10LL){
        cout<<"Test Output:\n\n";
        
        for(ll i = 1; i<=hi;i++){
            cout<<i<<": "<<getAnswer("1", to_string(i))<<"\n";
        }
        
}
void testSingleOutput(string val){
    cout<<"Ans: "<<getAnswer("1","val")<<"\n";
}
// Soln Link: https://www.codechef.com/viewsolution/26016457
int main(void)
{
    ios_base::sync_with_stdio(false);
    int t;
    // string testString = string(mx5,'9');
    // testSingleOutput(testString);
    
    // testOutput();
    cin>>t;
    while(t--){
        
        int nl,nr;
        string L, R;
        cin>>nl >>L;
        cin>>nr>>R;
        
        cout<<getAnswer(L,R)<<"\n";
    }
    
    return 0;
}
