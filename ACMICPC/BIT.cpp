//The following fenwick tree is 1-indexed and thus the array on which
// the fenwick tree is built should be also 1-indexed

#define LSOne(S) (S & (-S))
class BIT {
	int* ft, size;
public:
	// initialize a BIT of n elements to zero
	BIT(int n) {
		size = n;
		ft = new int[n+1];
	}

	~BIT()	{
		delete [] ft;
	}

	// returns sum of the range [1...b]
	int sum(int b) {
		int sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	// returns sum of the range [a...b]
	int sum(int a, int b) {
		return sum(b) - (a == 1 ? 0 : sum(a - 1));
	}

	// update value of the k-th element by v (v can be +ve/inc or -ve/dec)
	// i.e., increment or decrement kth element by a value v
	void update(int k, int v) {
		for (; k <= size; k += LSOne(k)) ft[k] += v;
	}

    // divide each original frequency by c
	void scaleDown(int c){
        for (int i=1 ; i<=size ; i++) ft[i] /= c;
    }

    // multiply each original frequency by c
    void scaleUp(int c){
        for (int i=1 ; i<=size ; i++) ft[i] *= c;
    }
};
//BIT for long long int 
class BIT {
	ll* ft, size;
public:
	// initialize a BIT of n elements to zero
	BIT(int n) {
		size = n;
		ft = new ll[n+1];
	}

	~BIT()	{
		delete [] ft;
	}

	// returns sum of the range [1...b]
	ll sum(ll b) {
		ll sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	// returns sum of the range [a...b]
	ll sum(ll a, ll b) {
		return sum(b) - (a == 1 ? 0 : sum(a - 1));
	}

	// update value of the k-th element by v (v can be +ve/inc or -ve/dec)
	// i.e., increment or decrement kth element by a value v
	void update(int k, ll v) {
		for (; k <= size; k += LSOne(k)) ft[k] += v;
	}

    // divide each original frequency by c
	void scaleDown(ll c){
        for (int i=1 ; i<=size ; i++) ft[i] /= c;
    }

    // multiply each original frequency by c
    void scaleUp(ll c){
        for (int i=1 ; i<=size ; i++) ft[i] *= c;
    }
};

