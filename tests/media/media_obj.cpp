#include <ffw/media.h>
#include "../catch.hpp"

static std::string mtl;

TEST_CASE("Open OBJ File", "[ObjLoader]") {
    ffw::ObjLoader obj;
    REQUIRE(obj.isOpen() == false);
    REQUIRE(obj.open("plane.obj"));
    REQUIRE(obj.isOpen() == true);
    REQUIRE(obj.getMtllibName() == "plane.mtl");

    obj.close();
    REQUIRE(obj.isOpen() == false);
}

TEST_CASE("Read indices from plane.obj", "[ObjLoader]") {
    ffw::ObjLoader obj;
    REQUIRE(obj.open("plane.obj"));
    REQUIRE(obj.isOpen());

    std::string name;
    REQUIRE(obj.calculatePolyCount() == 0);
    REQUIRE(obj.gotObject() == false);
    REQUIRE(obj.getNextObject(&name) == true);
    REQUIRE(obj.gotObject() == true);
    REQUIRE(name == "Plane");

    // Has to work multiple times
    REQUIRE(obj.calculatePolyCount() == 8);
    REQUIRE(obj.calculatePolyCount() == 8);

    // Quad #1
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());

    // Check for material
    REQUIRE(obj.getMaterialFoundFlag() == true);
    obj.resetMaterialFoundFlag();
    REQUIRE(obj.getMaterialFoundFlag() == false);
    REQUIRE(obj.getCurrentMaterialName() == "Material.001");

    // Values need to match plane.obj line 26
    REQUIRE(obj.getIndex0() == ffw::Vec3i(7, 1, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(9, 4, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(2, 2, 1));

    REQUIRE(obj.getPolygon());

    // No new material should appear
    REQUIRE(obj.getMaterialFoundFlag() == false);
    REQUIRE(obj.getIndex0() == ffw::Vec3i(2, 2, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(9, 4, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(6, 3, 1));

    // Quad #2
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());

    // Check for material
    REQUIRE(obj.getMaterialFoundFlag() == true);
    obj.resetMaterialFoundFlag();
    REQUIRE(obj.getCurrentMaterialName() == "Material.002");

    // Values need to match plane.obj line 28
    REQUIRE(obj.getIndex0() == ffw::Vec3i(1, 5, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(5, 6, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(7, 1, 1));

    REQUIRE(obj.getPolygon());

    // No new material should appear
    REQUIRE(obj.getMaterialFoundFlag() == false);
    REQUIRE(obj.getIndex0() == ffw::Vec3i(7, 1, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(5, 6, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(9, 4, 1));

    // Quad #3
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());

    // Check for material
    REQUIRE(obj.getMaterialFoundFlag() == true);
    obj.resetMaterialFoundFlag();
    REQUIRE(obj.getCurrentMaterialName() == "Material.003");

    // Values need to match plane.obj line 28
    REQUIRE(obj.getIndex0() == ffw::Vec3i(9, 4, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(8, 8, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(6, 3, 1));

    REQUIRE(obj.getPolygon());

    // No new material should appear
    REQUIRE(obj.getMaterialFoundFlag() == false);
    REQUIRE(obj.getIndex0() == ffw::Vec3i(6, 3, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(8, 8, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(4, 7, 1));

    // Quad #4
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());

    // Check for material
    REQUIRE(obj.getMaterialFoundFlag() == true);
    obj.resetMaterialFoundFlag();
    REQUIRE(obj.getCurrentMaterialName() == "Material.004");

    // Values need to match plane.obj line 28
    REQUIRE(obj.getIndex0() == ffw::Vec3i(5, 6, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(3, 9, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(9, 4, 1));

    REQUIRE(obj.getPolygon());

    // No new material should appear
    REQUIRE(obj.getMaterialFoundFlag() == false);
    REQUIRE(obj.getIndex0() == ffw::Vec3i(9, 4, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(3, 9, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(8, 8, 1));

    // End of polygons
    // There should not be any next polygon
    REQUIRE(obj.getPolygon() == false);
    REQUIRE(obj.gotObject() == false);

    // The OBJ file contains only one object
    REQUIRE(obj.getNextObject(&name) == false);
}

TEST_CASE("Read indices and v/vt/vn from planes.obj", "[ObjLoader]") {
    ffw::ObjLoader obj;
    REQUIRE(obj.open("plane.obj"));
    REQUIRE(obj.isOpen());

    std::string name;
    REQUIRE(obj.getNextObject(&name) == true);
    REQUIRE(obj.gotObject() == true);
    REQUIRE(name == "Plane");

    // Has to work multiple times
    REQUIRE(obj.calculatePolyCount() == 8);

    // Quad #1
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());

    // 7/1/1 - 9/4/1 - 2/2/1
    REQUIRE(obj.getVertex(0) == ffw::Vec3f(0, 0, 1)); // 7th vertex
    REQUIRE(obj.getVertex(1) == ffw::Vec3f(0, 0, 0)); // 9th vertex
    REQUIRE(obj.getVertex(2) == ffw::Vec3f(1, 0, 1)); // 2nd vertex

    // All normals in plane.obj are same
    REQUIRE(obj.getNormal(0) == ffw::Vec3f(0, 1, 0)); // 1st normal
    REQUIRE(obj.getNormal(1) == ffw::Vec3f(0, 1, 0)); // 1st normal
    REQUIRE(obj.getNormal(2) == ffw::Vec3f(0, 1, 0)); // 1st normal

    REQUIRE(obj.getTexCoord2(0) == ffw::Vec2f(0.5f, 0.0001f)); // 1st coord
    REQUIRE(obj.getTexCoord2(1) == ffw::Vec2f(0.5f, 0.5f)); // 4th coord
    REQUIRE(obj.getTexCoord2(2) == ffw::Vec2f(0.9999f, 0.0001f)); // 2nd coord

    REQUIRE(obj.getPolygon());

    // 2/2/1 - 9/4/1 - 6/3/1
    REQUIRE(obj.getVertex(0) == ffw::Vec3f(1, 0, 1)); // 2nd vertex
    REQUIRE(obj.getVertex(1) == ffw::Vec3f(0, 0, 0)); // 9th vertex
    REQUIRE(obj.getVertex(2) == ffw::Vec3f(1, 0, 0)); // 6th vertex

    // All normals in plane.obj are same
    REQUIRE(obj.getNormal(0) == ffw::Vec3f(0, 1, 0)); // 1st normal
    REQUIRE(obj.getNormal(1) == ffw::Vec3f(0, 1, 0)); // 1st normal
    REQUIRE(obj.getNormal(2) == ffw::Vec3f(0, 1, 0)); // 1st normal

    REQUIRE(obj.getTexCoord2(0) == ffw::Vec2f(0.9999f, 0.0001f)); // 2nd coord
    REQUIRE(obj.getTexCoord2(1) == ffw::Vec2f(0.5f, 0.5f)); // 4th coord
    REQUIRE(obj.getTexCoord2(2) == ffw::Vec2f(0.9999f, 0.5f)); // 3rd coord

    // Quad #2
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());

    // 1/5/1 - 5/6/1 - 7/1/1
    REQUIRE(obj.getVertex(0) == ffw::Vec3f(-1, 0, 1)); // 1st vertex
    REQUIRE(obj.getVertex(1) == ffw::Vec3f(-1, 0, 0)); // 5th vertex
    REQUIRE(obj.getVertex(2) == ffw::Vec3f(0, 0, 1)); // 7th vertex

    // All normals in plane.obj are same
    REQUIRE(obj.getNormal(0) == ffw::Vec3f(0, 1, 0)); // 1st normal
    REQUIRE(obj.getNormal(1) == ffw::Vec3f(0, 1, 0)); // 1st normal
    REQUIRE(obj.getNormal(2) == ffw::Vec3f(0, 1, 0)); // 1st normal

    REQUIRE(obj.getTexCoord2(0) == ffw::Vec2f(0.0001f, 0.0001f)); // 5th coord
    REQUIRE(obj.getTexCoord2(1) == ffw::Vec2f(0.0001f, 0.5f)); // 6th coord
    REQUIRE(obj.getTexCoord2(2) == ffw::Vec2f(0.5f, 0.0001f)); // 1st coord

    REQUIRE(obj.getPolygon());

    // 7/1/1 - 5/6/1 - 9/4/1
    REQUIRE(obj.getVertex(0) == ffw::Vec3f(0, 0, 1)); // 7th vertex
    REQUIRE(obj.getVertex(1) == ffw::Vec3f(-1, 0, 0)); // 5th vertex
    REQUIRE(obj.getVertex(2) == ffw::Vec3f(0, 0, 0)); // 9th vertex

    // All normals in plane.obj are same
    REQUIRE(obj.getNormal(0) == ffw::Vec3f(0, 1, 0)); // 1st normal
    REQUIRE(obj.getNormal(1) == ffw::Vec3f(0, 1, 0)); // 1st normal
    REQUIRE(obj.getNormal(2) == ffw::Vec3f(0, 1, 0)); // 1st normal

    REQUIRE(obj.getTexCoord2(0) == ffw::Vec2f(0.5f, 0.0001f)); // 1st coord
    REQUIRE(obj.getTexCoord2(1) == ffw::Vec2f(0.0001f, 0.5f)); // 6th coord
    REQUIRE(obj.getTexCoord2(2) == ffw::Vec2f(0.5f, 0.5f)); // 4th coord

    // Quad #3
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());

    // Quad #4
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());

    // End of file
    REQUIRE(obj.getPolygon() == false);
}

TEST_CASE("Read indices from cylinder.obj", "[ObjLoader]") {
    ffw::ObjLoader obj;
    REQUIRE(obj.open("cylinder.obj"));
    REQUIRE(obj.isOpen());

    std::string name;
    REQUIRE(obj.getNextObject(&name) == true);
    REQUIRE(obj.gotObject() == true);
    REQUIRE(obj.getMtllibName() == "cylinder.mtl");
    REQUIRE(name == "Cylinder");

    // Has to work multiple times
    REQUIRE(obj.calculatePolyCount() == 28);
    REQUIRE(obj.calculatePolyCount() == 28);

    // Check for material
    REQUIRE(obj.getMaterialFoundFlag() == true);
    obj.resetMaterialFoundFlag();
    REQUIRE(obj.getCurrentMaterialName() == "None");

    // Line 67
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(1, 1, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(3, 4, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(2, 2, 1));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(2, 2, 1));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(3, 4, 1));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(4, 3, 1));

    // Line 68
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(3, 4, 2));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(5, 6, 2));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(4, 3, 2));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(4, 3, 2));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(5, 6, 2));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(6, 5, 2));

    // Line 69
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());
    // Line 70
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());
    // Line 71
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());
    // Line 72
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());

    // Line 73
    // always 0, counter +2, counter+1
    // The line 73 is a 8 sided polygon...
    // How many triangles can you fit in there, where one point is always at 0th index?
    // 6 triangles:
    // 0: 0,2,1
    // 1: 0,3,2
    // 2: 0,4,3
    // 3: 0,5,4
    // 4: 0,6,5
    // 5: 0,7,6
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(4, 17, 7));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(16, 19, 7));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(2, 18, 7));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(4, 17, 7));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(14, 20, 7));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(16, 19, 7));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(4, 17, 7));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(12, 21, 7));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(14, 20, 7));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(4, 17, 7));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(10, 22, 7));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(12, 21, 7));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(4, 17, 7));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(8, 23, 7));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(10, 22, 7));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(4, 17, 7));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(6, 24, 7));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(8, 23, 7));

    // Line 74
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(13, 16, 8));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(15, 26, 8));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(14, 15, 8));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(14, 15, 8));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(15, 26, 8));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(16, 25, 8));

    // Line 75
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());

    // Line 76
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getPolygon());

    // End of file
    REQUIRE(obj.getPolygon() == false);
}

TEST_CASE("Get multiple objects from planes.obj", "[ObjLoader]") {
    ffw::ObjLoader obj;
    REQUIRE(obj.open("planes.obj"));
    REQUIRE(obj.isOpen());

    REQUIRE(obj.gotObject() == false);

    std::string name;
    REQUIRE(obj.getNextObject(&name) == true);
    REQUIRE(obj.gotObject() == true);
    REQUIRE(obj.getMtllibName() == "planes.mtl");
    REQUIRE(name == "Plane.002");
    REQUIRE(obj.gotObject());

    REQUIRE(obj.calculatePolyCount() == 2);

    REQUIRE(obj.getNextObject(&name) == true);
    REQUIRE(obj.gotObject() == true);
    REQUIRE(obj.getMtllibName() == "planes.mtl");
    REQUIRE(name == "Plane.001");
    REQUIRE(obj.gotObject());

    REQUIRE(obj.calculatePolyCount() == 2);
    REQUIRE(obj.gotObject());
    REQUIRE(obj.objectHasNormals());
    REQUIRE(obj.objectHasTexcoords());

    // Line 29
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(5, 5, 2));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(7, 8, 2));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(6, 6, 2));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(6, 6, 2));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(7, 8, 2));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(8, 7, 2));

    REQUIRE(obj.getPolygon() == false);
    REQUIRE(obj.gotObject() == false);

    REQUIRE(obj.getNextObject(&name) == true);
    REQUIRE(obj.gotObject() == true);
    REQUIRE(obj.getMtllibName() == "planes.mtl");
    REQUIRE(name == "Plane");

    REQUIRE(obj.calculatePolyCount() == 2);
    REQUIRE(obj.gotObject());
    REQUIRE(obj.objectHasNormals());
    REQUIRE(obj.objectHasTexcoords());

    // Line 42
    // first 0,3,1 then 1,3,2
    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(9, 9, 3));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(11, 12, 3));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(10, 10, 3));

    REQUIRE(obj.getPolygon());
    REQUIRE(obj.getIndex0() == ffw::Vec3i(10, 10, 3));
    REQUIRE(obj.getIndex1() == ffw::Vec3i(11, 12, 3));
    REQUIRE(obj.getIndex2() == ffw::Vec3i(12, 11, 3));

    REQUIRE(obj.getPolygon() == false);
    REQUIRE(obj.gotObject() == false);
}