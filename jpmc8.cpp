#include <bits/stdc++.h>
using namespace std;

bool isIdSegment(const string &seg) {
    if (seg.size() < 3) return false;
    if (seg.rfind("id", 0) == 0) {
        for (size_t i = 2; i < seg.size(); i++) {
            if (!isdigit(seg[i])) return false;
        }
        return true;
    }
    return false;
}

string extractResource(const string &url) {
    size_t pos = url.find("://");
    if (pos != string::npos) {
        pos = url.find('/', pos + 3);
        if (pos == string::npos) return "";
    } else {
        pos = 0;
    }
    string path = url.substr(pos);
    while (!path.empty() && path.back() == '/') path.pop_back();
    
    vector<string> segments;
    stringstream ss(path);
    string seg;
    while (getline(ss, seg, '/')) {
        if (!seg.empty() && !isIdSegment(seg)) {
            segments.push_back(seg);
        }
    }
    if (segments.empty()) return "";
    
    ostringstream oss;
    oss << segments[0];
    for (size_t i = 1; i < segments.size(); i++) oss << "/" << segments[i];
    return oss.str();
}

vector<string> processUrls(const vector<string>& urls) {
    unordered_set<string> seen;
    vector<string> resources;

    for (const auto &url : urls) {
        string resource = extractResource(url);
        if (!resource.empty()) {
            // seen.insert(resource);
            resources.push_back(resource);
        }
    }

    // Sorting by depth first, then lexicographically
    sort(resources.begin(), resources.end(), [](const string &a, const string &b) {
        int depthA = count(a.begin(), a.end(), '/');
        int depthB = count(b.begin(), b.end(), '/');
        return depthA == depthB ? a < b : depthA < depthB;
    });

    return resources;
}

int main() {
    // vector<string> urls = {
    //     "https://api.example.com/resource2/id1/resource3/id2",
    //     "https://api.example.com/resource3/",
    //     "https://api.example.com/resource2/",
    //     "https://api.example.com/resource1/id1/resource3/id2"
    // };
    int n; cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<string> ans = processUrls(a);\
    set<string> st;
    for(auto it:ans) st.insert(it);
    for(auto it:ans) cout<<it<<endl;

    return 0;
}
