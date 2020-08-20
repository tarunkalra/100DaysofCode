struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
int ans = INT_MIN;
int pathSum(Node *root){
    if(!root)
        return 0;
    int left=INT_MIN,right=INT_MIN;
    if(root->left)
        left = pathSum(root->left);
    if(root->right)
        right = pathSum(root->right);
    if(root->left!=NULL && root->right!=NULL )
    ans = max(ans,(root->data + left + right));
    //cout<<max(root->data+left,root->data+right)<<" "<<endl;
    int mx = max(left,right);
    if(mx==INT_MIN)
        mx = 0;
    return mx + root->data;
}

int maxPathSum(Node* root)
{ 
    // code here   
    ans = INT_MIN;
    Node* A = root;
    if(!root)
        return 0;
    
    int lol = pathSum(root);
    if(ans==INT_MIN)
        return 0;
    return ans;
    
}
