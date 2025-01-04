#include "raylib.h"
#include "raymath.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct {
    Vector2 Direction;
    Vector2 Normal;
} ViewRay;

typedef struct {
    ViewRay Left;
    ViewRay Right;

    Vector2 Forward;
    Vector2 Position;
} View;

typedef enum {
    Outside = 0,
    Contained = 1,
    Intersecting = 2,
} ViewInteresectionType;

ViewInteresectionType SphereNearViewRay(
    Vector2 origin, ViewRay* ray, Vector2 center, float radius)
{
    // get the vector from the origin to the point to test
    Vector2 vecToPoint = Vector2Subtract(center, origin);

    // get the dot product between the ray and the vector to the point
    float dotForPoint = Vector2DotProduct(ray->Direction, vecToPoint);

    Vector2 nearestPoint = { origin.x + ray->Direction.x * dotForPoint,
        origin.y + ray->Direction.y * dotForPoint };

    DrawCircleV(nearestPoint, 5, BLUE);

    float normDot = Vector2DotProduct(ray->Normal, vecToPoint);

    DrawText(TextFormat("%2.2f", normDot), nearestPoint.x - 20,
        nearestPoint.y + 10, 10, WHITE);

    if (normDot < radius) {
        if (fabsf(normDot) <= radius) {
            return Intersecting;
        } else {
            if (normDot <= 0)
                return Contained;
        }
    }

    return Outside;
}

// clang-format off
// setup a view
void InitView(
        View* view,
        Vector2 position,
        float startingAngle,
        float fov
    )
{
    Matrix mat = MatrixRotateZ(startingAngle * DEG2RAD);
    view->Forward = Vector2Transform((Vector2) {0, -1},mat);
    view->Position = position;

    mat = MatrixRotateZ(startingAngle + fov / 2.0f * DEG2RAD);
    view->Left.Direction = Vector2Transform((Vector2) { 0, 1},mat);
    view->Left.Normal = Vector2Transform((Vector2) {-1, 0},mat);

    mat = MatrixRotateZ(startingAngle - fov / 2.0f * DEG2RAD);
    view->Right.Direction = Vector2Transform((Vector2) { 0, -1},mat);
    view->Right.Normal = Vector2Transform((Vector2) {-1, 0},mat);
}
// clang-format on

void RotateView(View* view, float angle)
{
    Matrix mat = MatrixRotateZ(angle * DEG2RAD);

    view->Forward = Vector2Transform(view->Forward, mat);
    view->Left.Direction = Vector2Transform(view->Left.Direction, mat);
    view->Left.Normal = Vector2Transform(view->Left.Normal, mat);
    view->Right.Direction = Vector2Transform(view->Right.Direction, mat);
    view->Right.Normal = Vector2Transform(view->Right.Normal, mat);
}

void DrawView(View* view)
{
    DrawCircleV(view->Position, 5, LIGHTGRAY);

    // left view
    Vector2 viewExtension
        = Vector2Add(view->Position, Vector2Scale(view->Left.Direction, 500));
    DrawLineV(view->Position, viewExtension, PURPLE);
    Vector2 normalPoint
        = Vector2Add(view->Position, Vector2Scale(view->Left.Direction, 200));
    Vector2 normalExtension
        = Vector2Add(normalPoint, Vector2Scale(view->Left.Normal, 20));
    DrawLineV(normalPoint, normalExtension, PURPLE);

    // right view
    viewExtension
        = Vector2Add(view->Position, Vector2Scale(view->Right.Direction, 500));
    DrawLineV(view->Position, viewExtension, PURPLE);
    normalPoint
        = Vector2Add(view->Position, Vector2Scale(view->Right.Direction, 200));
    normalExtension
        = Vector2Add(normalPoint, Vector2Scale(view->Right.Normal, 20));
    DrawLineV(normalPoint, normalExtension, VIOLET);
}

// test the circle against both sides of the view
ViewInteresectionType CircleInView(View* view, Vector2 center, float radius)
{
    // get intersection for left and right
    ViewInteresectionType left
        = SphereNearViewRay(view->Position, &view->Left, center, radius);
    ViewInteresectionType right
        = SphereNearViewRay(view->Position, &view->Right, center, radius);

    // if it is outside and edge it is outside the view
    if (left == Outside || right == Outside)
        return Outside;

    if (left == Contained && right == Contained)
        return Contained;

    return Intersecting;
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib example basic");

    SetTargetFPS(90);

    float radius = 50;
    View view;
    InitView(&view, (Vector2) { 400, 425 }, 0, 60);

    // Main loop
    while (!WindowShouldClose()) {
        float angle = 0;

        if (IsKeyDown(KEY_LEFT))
            angle += 90 * GetFrameTime();
        if (IsKeyDown(KEY_RIGHT))
            angle -= 90 * GetFrameTime();

        // change the radius
        if (IsKeyDown(KEY_UP))
            angle += 50 * GetFrameTime();
        if (IsKeyDown(KEY_DOWN))
            angle -= 25 * GetFrameTime();

        RotateView(&view, angle);

        // get a point to test
        Vector2 point = GetMousePosition();

        BeginDrawing();

        ClearBackground(BLACK);

        DrawView(&view);

        DrawCircleV(point, 5, BLUE);

        Color c = RED;

        ViewInteresectionType t = CircleInView(&view, point, radius);

        if (t == Intersecting)
            c = YELLOW;
        else if (t == Contained)
            c = GREEN;

        DrawCircleLinesV(point, radius, c);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
