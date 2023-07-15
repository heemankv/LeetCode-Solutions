class Solution {

    bool toposort(vector<int> dependency[], vector<int>& indegree, int numCourses){

        // make queue
        queue<int> order;
        int answer = 0;
        
        // push all the indegree = 0 to the queue
        for(const auto elem:indegree){
            //  if freq of element is zero pass the elem;
            cout<<elem.first<<" "<<elem.second<<endl;
            if(elem.second == 0){
                order.push(elem.first);
                cout<< elem.first << " is here"<< endl;
            }
        }
    
        //  while(!queue.empty){
        while(!order.empty()){
            int elem = order.front();
            order.pop();
            answer++;

            for(const auto dep:dependency[elem]){
                indegree[dep]--;
                if(indegree[dep] == 0){
                    order.push(dep);
                }
            }
        }
        cout<<answer<<endl;
        return answer == numCourses;
    }




public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //  define adj
        if(numCourses == 1 || prerequisites.size() == 0) return true;
        vector<int> dependency[numCourses]; // 2D matrix
        // define indegree
        vector<int> indegree; // element to frequency


        for(int i  = 0; i < numCourses; i++){
            indegree[i] = 0;
        }

        // make indegree map 
        // might have to convert prereq to adj 
        for(const auto arrow:prerequisites){
            // fill indegree
        
            indegree[arrow[1]]++;
            // fill adj -> directed adj list
            dependency[arrow[0]].push_back(arrow[1]);
        }

        return toposort(dependency, indegree, numCourses);  
    }
};
