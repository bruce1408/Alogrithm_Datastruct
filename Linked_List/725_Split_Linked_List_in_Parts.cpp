vector<ListNode*> splitListToParts(ListNode* root, int k)
{
    vector<ListNode *> res(k);
    ListNode * cur = root;
    int cnt = 0;
    while(root) // 计算总长度
    {
        cnt++;
        cur = cur->next;
    }
    cur = root;
    int avg = cnt/k, ext = cnt%k;
    for (int i=0;i<k && root ;i++)
    {
        res[i] = root;
        for(int j=1;j<avg + (i<ext);j++)
        {
            root = root->next;
        }
        ListNode *t = root->next;
        root->next = NULL;
        root = t;
    }
    return res;   
}