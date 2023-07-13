class Solution {

// USING BFS



public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int numR = image.size();
        int numC = image[0].size();
        // adj list banao jara jaldi si
        // no need for adj trraversal 4 side fixed hai


        // 4 side traversal 
        int dx[4] = {0,0,-1,+1};
        int dy[4] = {-1,+1,0,0};

        // now do traversal
        vector<vector<int>> visited(numR,vector<int>(numC,0));


        //  row,col
        queue<pair<int,int>> order;

        // push initial
        order.push({sr,sc});
        visited[sr][sc] = 1;


        while(!order.empty()){
            auto element = order.front();
            order.pop();

            // iterate on all the elements adj to this guy

            for(int i = 0 ; i<4; i++){

                int newR = element.first  + dx[i];
                int newC = element.second + dy[i];

                if((newR < numR && newR >=0) &&  (newC < numC && newC >=0)){
                    // valid adj node 
                    //not visited 
                    if(!visited[newR][newC]){
                        // not visited
                        // should be of the same colour as me 
                        if(image[element.first][element.second] == image[newR][newC]){
                            order.push({newR,newC});
                            visited[newR][newC] = 1;
                        }
                    }
                }
            }
            // mark me as the colour needed
            image[element.first][element.second] = color;
        }

        return image;
    }
};
