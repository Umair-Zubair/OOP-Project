class maze{
    private:
    enum {width = 8, height = 8};
    int graph[width][height];
    int frame = 0;
    int obstacles[width][height];
    int obstacleCount=0;
    public:
    maze();
    void makeGraph();
    void firstFrame();
    void secondFrame();
    void thirdFrame();
    void fourthFrame();
    void placeObstacles();
    bool isValidMove(int x, int y) const;
};