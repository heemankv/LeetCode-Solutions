class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // define indegree 
        vector<int> inDegree(numCourses);
        // b -> a
        //  for loop to make ingree. ==> (index -> value)
        for(const auto prereq:prerequisites){
            inDegree[prereq[1]]++;
        }

        // need adj list to perfom the topo sort ==> (value -> value)
        vector<vector<int>> adj(numCourses, vector<int>());
        for(const auto prereq:prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
        }
        // I have the adj list now

        // Indegree ready
        queue<int> que;

        // push all elem with indegree == 0 to queue
        for(int i =0 ; i < numCourses; i++){
            if(inDegree[i] == 0){
                que.push(i);
            }
        }
        int count = 0;
        vector<int> answer;
        //  final while loop to iterate over on all the nodes
        while(!que.empty()){
           
            int elem = que.front();
            answer.push_back(elem);
            que.pop();
            // this you has indegree == 0, so count++
            count++;

            // now what ?

            // go to all my adj and do a inDegree--

            for(const auto adjcent:adj[elem]){

                inDegree[adjcent]--;
                if(inDegree[adjcent] == 0){
                    que.push(adjcent);
                } 
            }
        }

        // if count != nums then false else true;
        if(count == numCourses){
            reverse(answer.begin(), answer.end());
            return answer;
        }else{
            vector<int> ans; 
            return ans;
        }
    }
};
