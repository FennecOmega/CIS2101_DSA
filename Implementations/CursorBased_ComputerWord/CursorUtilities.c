void initVH(VirtualHeap *V)
{
    int i;
    for (i = 0; i < VH_MAX; i++)
    {
        V->Nodes[i].link = i - 1;
    }
    V->avail = VH_MAX - 1;
    V->isInit = true;
}

int AllocSpace(VirtualHeap *V)
{
    int AvailNode = V->avail;
    if (AvailNode != -1)
    {
        V->avail = V->Nodes[AvailNode].link;
    }
    return AvailNode;
}

void deallocSpace(VirtualHeap *V, int pos)
{
    if (pos > -1 && pos < VH_MAX)
    {
        V->Nodes[pos].link = V->avail;
        V->avail = pos;
    }
}