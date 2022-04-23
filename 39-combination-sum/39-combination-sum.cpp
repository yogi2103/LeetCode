class Solution {
public:
void combinationSumHelper(vector<int>& arr,vector<int>&Helper,int idx,int n,vector<vector<int>>&v,int target){
	if(target==0){
		v.push_back(Helper);
		return;
	}
	//if we are including the element
	int i=idx;
	int j=n-1;
	while(i<=j && arr[i]<=target){
		Helper.push_back(arr[i]);
		combinationSumHelper(arr,Helper,i,n,v,target-arr[i]);
		Helper.pop_back();
		i++;
	}
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
	vector<vector<int>>v;
	vector<int>Helper;
	combinationSumHelper(candidates,Helper,0,candidates.size(),v,target);
	return v;
}
};