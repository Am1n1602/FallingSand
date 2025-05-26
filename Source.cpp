#include <raylib.h>
#include <vector>

int main()
{
	const int SCREENWIDTH = 1000;
	const int SCREENHEIGHT = 600;

	InitWindow(SCREENWIDTH, SCREENHEIGHT, "FallingSand");
	SetTargetFPS(120);

	std::vector<Vector2> Positions;
	std::vector<Vector2> Velocity;

	const int CELL_SIZE = 10;
	const int GRID_WIDTH = SCREENWIDTH / CELL_SIZE;
	const int GRID_HEIGHT = SCREENHEIGHT / CELL_SIZE;
	std::vector<std::vector<bool>> grid(GRID_WIDTH, std::vector<bool>(GRID_HEIGHT, false));


	while (!WindowShouldClose())
	{
	float dt = GetFrameTime();
		BeginDrawing();
		ClearBackground(BLACK);

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			Vector2 Mousy = GetMousePosition();
			Mousy.x = (int(Mousy.x) / CELL_SIZE) * CELL_SIZE;
			Mousy.y = (int(Mousy.y) / CELL_SIZE) * CELL_SIZE;
			Positions.push_back(Mousy);
			Velocity.push_back({ 0,1 });
			int cellX = int(Mousy.x) / CELL_SIZE;
			int cellY = int(Mousy.y) / CELL_SIZE;
			if (cellX <= SCREENWIDTH) {
				cellX = 1;
			}
			if(cellX >= SCREENWIDTH) {
				cellX = SCREENWIDTH-1;
			}
			if (cellY <= SCREENHEIGHT){
				cellY = 1;
			}
			if(cellY >= SCREENHEIGHT) {
				cellY = SCREENHEIGHT-1;
			}
			grid[cellX][cellY] = true;
		}

		for (int w = 0; w < Positions.size(); w++) {
			if (Velocity[w].y == 1) {
				int cellX = int(Positions[w].x) / CELL_SIZE;
				int cellY = int(Positions[w].y) / CELL_SIZE;
				int nextCellY = cellY + 1;

				if (nextCellY >= GRID_HEIGHT || grid[cellX][nextCellY]) {
					Velocity[w].y = 0;
					grid[cellX][cellY] = true;
				}
				else {
					grid[cellX][cellY] = false;
					Positions[w].y += CELL_SIZE;
					grid[cellX][nextCellY] = true;
				}
			}
		}	

		for (int i = 0;i < SCREENWIDTH;i+=CELL_SIZE) {
			DrawLine(0+i, 0, 0+i, SCREENHEIGHT, RED);
		}

		for (int j = 0;j < SCREENHEIGHT;j += CELL_SIZE) {
			DrawLine(0, 0+j, SCREENWIDTH, 0+j, RED);
		}

		for (int k = 0;k < Positions.size();k++) {
			DrawRectangleV(Positions[k], { CELL_SIZE,CELL_SIZE }, YELLOW);
		}

		EndDrawing();
	}
	CloseWindow();

	return 0;
}