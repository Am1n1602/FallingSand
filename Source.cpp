#include <raylib.h>
#include <vector>

int main()
{
	const int SCREENWIDTH = 1280;
	const int SCREENHEIGHT = 780;

	InitWindow(SCREENWIDTH, SCREENHEIGHT, "FallingSand");
	SetTargetFPS(60);

	std::vector<Vector2> Positions;
	std::vector<Vector2> Velocity;

	const int CELL_SIZE = 15;
	const int GRID_WIDTH = SCREENWIDTH / CELL_SIZE;
	const int GRID_HEIGHT = SCREENHEIGHT / CELL_SIZE;
	std::vector<std::vector<bool>> grid(GRID_WIDTH*100, std::vector<bool>(GRID_HEIGHT*100, false));
	
	Color Charcoal = { 30, 30, 30 ,255 };
	Color LightChar = { 60, 60, 60 ,255 };
	Color Sandy = { 244, 180, 0 ,255 };
	Color CoolBlue = { 174, 234, 255 ,255 };


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(Charcoal);

		if (IsKeyPressed(KEY_Q)) {
			Positions.clear();
			Velocity.clear();
			for (int i = 0;i<GRID_WIDTH;i++) {
				for (int j = 0;j < GRID_HEIGHT;j++) {
					grid[i][j] = false;
				}
			}
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			Vector2 Mousy = GetMousePosition();
			Mousy.x = (int(Mousy.x) / CELL_SIZE) * CELL_SIZE;
			Mousy.y = (int(Mousy.y) / CELL_SIZE) * CELL_SIZE;
			Positions.push_back(Mousy);
			Velocity.push_back({ 0,1 });
			int cellX = int(Mousy.x) / CELL_SIZE;
			int cellY = int(Mousy.y) / CELL_SIZE;
			if (cellX <= 0) {
				cellX = 0;
			}
			if (cellY <= 0) {
				cellY =0;
			}
			grid[cellX][cellY] = true;
		}



		for (int w = 0; w < Positions.size(); w++) {
			if (Velocity[w].y == 1) {
				int cellX = int(Positions[w].x) / CELL_SIZE;
				int cellY = int(Positions[w].y) / CELL_SIZE;
				if (cellY <= 0) {
					cellY = 0;
				}
				if (cellX <= 0) {
					cellX = 0;
				}
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
			else {
				if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
					Velocity[w].y = 1;

				}
			}
		}	

		for (int i = 0;i < SCREENWIDTH;i+=CELL_SIZE) {
			DrawLine(0+i, 0, 0+i, SCREENHEIGHT, LightChar);
		}

		for (int j = 0;j < SCREENHEIGHT;j += CELL_SIZE) {
			DrawLine(0, 0+j, SCREENWIDTH, 0+j, LightChar);
		}

		for (int k = 0;k < Positions.size();k++) {
			DrawRectangleV(Positions[k], { CELL_SIZE,CELL_SIZE }, Sandy);
		}
		DrawText("Press Q to reset the board! ", 50, 50, 20, CoolBlue);
		DrawText("Press LMB to spawn the sand! ", 50, 100, 20, CoolBlue);
		DrawText("Press RMB to unfreeze the sand! ", 50, 150, 20, CoolBlue);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}