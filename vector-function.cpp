#include <bits/stdc++.h>

using namespace std;

const float PI = 3.14159265;

float radianToDegree(float radian)
{
    return (radian * 180) / PI;
}

float degereeToRadian(float degree)
{
    return (degree * PI) / 180;
}

float norm(vector<float> v)
{
    float res = 0;
    for (auto x: v)
        res += pow(x, 2);

    return sqrt(res);
}

vector<float> toDroneAxis(vector<float> de, float bearing)
{
    float d2D = norm({de[0], de[1]});

    return {d2D * cos(degereeToRadian(bearing)), d2D * sin(degereeToRadian(bearing)), de[2]};
}

int main()
{
    // Input values
    vector<float> target(3);
    cout << "Input target position\n";
    for (int i = 0; i < 3; i++)
    {
        cout << (char) ('X' + i) << ": ";

        cin >> target[i];
    }

    vector<float> dronePos(3);
    float rumbo;
    cout << "Input drone position\n";
    for (int i = 0; i < 3; i++)
    {
        cout << (char) ('X' + i) << ": ";

        cin >> dronePos[i];
    }
    cout << "Drone heading angle (in degrees): "; cin >> rumbo;

    // get target distance
    // decomposed to earth axis
    vector<float> de(3);
    for (int i = 0; i < 3; i++)
        de[i] = target[i] - dronePos[i];

    // angle between drone heading and target
    float bearing = radianToDegree(atan(de[1] / de[0])) - rumbo;

    // get target distance
    // decomposed to drone body axis
    vector<float> d = toDroneAxis(de, bearing);
    for (auto x: d)
        cout << x << " ";
    cout << "\n";

    return 0;
}
