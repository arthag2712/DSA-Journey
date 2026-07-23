class Twitter {
public:
    int timer;

    // user -> people they follow
    unordered_map<int, unordered_set<int>> followMap;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweetMap;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timer++, tweetId});
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {

        // user should always see their own tweets
        followMap[userId].insert(userId);

        // {time, tweetId, userId, indexInUserTweets}
        priority_queue<vector<int>> pq;

        for (int user : followMap[userId]) {
            if (tweetMap[user].empty()) continue;

            int idx = tweetMap[user].size() - 1;

            pq.push({
                tweetMap[user][idx].first,   // time
                tweetMap[user][idx].second,  // tweetId
                user,
                idx
            });
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            if (idx > 0) {
                idx--;

                pq.push({
                    tweetMap[user][idx].first,
                    tweetMap[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }
};