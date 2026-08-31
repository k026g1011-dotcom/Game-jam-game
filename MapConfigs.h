#pragma once
namespace MapConfig
{
    inline constexpr int kWindowWidth = 1280;
    inline constexpr int kWindowHeight = 720;
    inline constexpr char WallChar = '#';
    inline constexpr char FloorChar = '.';
    inline constexpr char PlayerChar = '@';
    inline constexpr char RedBlockChar = 'R';
    inline constexpr char GreenBlockChar = 'G';
    inline constexpr char BlueBlockChar = 'B';
    inline constexpr char RedBaseChar = 'r';
    inline constexpr char GreenBaseChar = 'g';
    inline constexpr char BlueBaseChar = 'b';
    inline constexpr char StarChar = '*';
    inline constexpr int MapRows = 10;
    inline constexpr int MapCols = 10;
    inline constexpr float TileWidth = 32.0f;
    inline constexpr float TileHeight = 32.0f;
    inline constexpr char TestLevel[MapRows][MapCols + 1] = {
           "##########",
           "#...@...r#",
           "#.G...R..#",
           "#g.......#",
           "#....#...#",
           "#.### #..#",
           "#.#*.#...#",
           "#.##B#####",
           "#.......b#",
           "##########",
    };
    inline constexpr char FirstLevel[MapRows][MapCols + 1] = {
          "   ###    ",
          "   #r#    ",
          "   #.#    ",
          "   #.#    ",
          "####R#####",
          "#@.*G...g#",
          "####B#####",
          "   #.#    ",
          "   #b#    ",
          "   ###    ",
    };
    inline constexpr char SecondLevel[MapRows][MapCols + 1] = {
       "##########",
       "#...@...r#",
       "#.G...R..#",
       "#g.......#",
       "#....#...#",
       "#.### #..#",
       "#.#*.#...#",
       "#.##B#####",
       "#.......b#",
       "##########",
    };
    inline constexpr char ThirdLevel[MapRows][MapCols + 1] = {
       "##########",
       "#........#",
       "#B###R#..#",
       "#.# #.#.*#",
       "#.###.####",
       "#....g...#",
       "#.###.#..#",
       "#@# #G#..#",
       "#b# #r#..#",
       "### ######",
    };
    inline constexpr char FourthLevel[MapRows][MapCols + 1] = {
          "##########",
          "#...@#####",
          "#.....GRr#",
          "#g...#####",
          "#....#    ",
          "#.###     ",
          "#.#*.#    ",
          "#.##B#####",
          "#.......b#",
          "##########",
    };
    inline constexpr char FifthLevel[MapRows][MapCols + 1] = {
   "##########",
   "#.R.....r#",
   "#.######g#",
   "#..B....b#",
   "#####.##.#",
   "#@.....G.#",
   "#.###.##.#",
   "#.# ####.#",
   "#.#    #*#",
   "###    ###",
    };
}