vector<vector<int> > ff(vector<vector<int> >& image, int sr, int sc, int newColor, int initialColor) {
    if(sr>=image.size() || sr<0 || sc>=image[0].size() || sc<0) {
        return image;
    }
    image[sr][sc]=-1;
    vector<vector<int> > temp = image;
    if((sr-1)>=0 && image[sr-1][sc]==initialColor) temp = ff(temp,sr-1,sc,newColor,initialColor);
    if((sr+1)<image.size() && image[sr+1][sc]==initialColor) temp = ff(temp,sr+1,sc,newColor,initialColor);
    if((sc-1)>=0 && image[sr][sc-1]==initialColor) temp = ff(temp,sr,sc-1,newColor,initialColor);
    if((sc+1)<image[0].size() && image[sr][sc+1]==initialColor) temp = ff(temp,sr,sc+1,newColor,initialColor);
    
    return temp;

}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialcolor = image[sr][sc];
        vector<vector<int>> output =  ff(image,sr,sc,newColor,initialcolor);
        for(int i = 0; i<output.size();i++){
            for(int j=0;j<output[0].size();j++){
                if(output[i][j]==-1) output[i][j] = newColor;
            }
        }
        return output;
    }
};