struct node {
    int totTime, hLeft, vertex;

	// define sort order for comparisons in a sort function
    friend bool operator<(const node &a, const node &b) { 
        return a.totTime > b.totTime;
    }
};