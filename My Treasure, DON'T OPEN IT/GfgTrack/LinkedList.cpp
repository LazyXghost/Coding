/* Floyd cycle detection
    it basically makes two pointers
    slow and fast(moves twice the speed of slow)
    if they meet in between there exists a loop
    otherwise we get null at fast

    fast will enter loop before slow
    when slow enters fast will be already present in loop
    loop length = n
    distance between them = k(0<=k<n)
    now distance keeps on increasing by one
    when distance becomes equal to n they will be pointing to same pointer

    TIME COMPLEXITY-:
        slow reaches first loop node
        O(nodes - n)
        +
        fast and slow meets
        O(n)
        = O(nodes)
 */

/* Remove loop
    detect cycle using floyd and find there meeting point
    now move slow to head and move both slow and fast at same speed
    they will meet at starting node of loop

    Proof-:
    LINKED LIST(detect and remove loop)

    let
    m - distance of loop node from head
    k - distance of meeting point from loop node
    n - loop length
    x - iterations made by slow in loop before meeting
    y - iterations made by fast in loop before meeting

    (distance travelled by slow)*2 = distance travelled by fast
    (m+k+x*n)*2 = (m+k+y*n)
    m+k = n*(y - 2x)

    so m+k is multiple of n
    so if we start slow from head then in m it will came at loop node
    also fast node will  come at loop node because 
    meeting node is k distance ahead of loop node
    and in m+k it comes at meeting node
    so in m it will come at loop node
 */

/* LRU Cache
    if we access something from cache we move it to most recent
    also if we insert something it also goes to most recent position
    if cache is full then we remove least recently used and then add new element
 */