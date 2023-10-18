void heap_swap(vector<int> &bao, int x, int y)
{
    int tmp = bao[x];
    bao[x] = bao[y];
    bao[y] = tmp;
}
void heapify_up(vector<int> &bao)
{
    int idx = bao.size() - 1;
    while (idx > 0)
    {
        if (bao[pa(idx)] < bao[idx])
        {
            heap_swap(bao, pa(idx), idx);
            idx = pa(idx);
        }
        else
            break;
    }
}

void heapify_down(vector<int> &bao)
{
    int idx = 0;
    int left = lc(idx);
    int right = rc(idx);

    while (left < bao.size() || right < bao.size())
    {
        int mx = idx;
        if (left < bao.size() && bao[left] > bao[idx])
        {
            mx = left;
        }
        if (right < bao.size() && bao[right] > bao[mx])
        {
            mx = right;
        }
        if (idx == mx)
            break;

        heap_swap(bao, idx, mx);
        idx = mx;
        left = lc(idx);
        right = rc(idx);
    }
}

int extract_max(vector<int> &bao)
{
    int result = bao[0];

    bao[0] = bao[bao.size() - 1];
    bao.pop_back();
    heapify_up(bao);

    return result;
}

void insert(vector<int> &bao, int val)
{
    bao.push_back(val);
    heapify_up(bao);
}
