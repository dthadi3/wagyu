#include "catch.hpp"

#include <mapbox/geometry/wagyu/edge.hpp>

using namespace mapbox::geometry::wagyu;
using T = std::int64_t;

TEST_CASE("test edge initialization - same two points") {
    mapbox::geometry::point<T> p1 = { 100, 10 };
    mapbox::geometry::point<T> p2 = { 100, 10 };
    edge<T> e1(p1, p2, polygon_type_subject);

    CHECK(e1.bot.x == 100);
    CHECK(e1.bot.y == 10);
    CHECK(e1.curr.x == 100);
    CHECK(e1.curr.y == 10);
    CHECK(e1.top.x == 100);
    CHECK(e1.top.y == 10);
    CHECK(e1.dx == Approx(HORIZONTAL));
    CHECK(e1.next == nullptr);
    CHECK(e1.prev == nullptr);
    CHECK(e1.next_in_LML == nullptr);
    CHECK(e1.next_in_AEL == nullptr);
    CHECK(e1.prev_in_AEL == nullptr);
    CHECK(e1.next_in_SEL == nullptr);
    CHECK(e1.prev_in_SEL == nullptr);
    CHECK(e1.winding_count == 0);
    CHECK(e1.winding_count2 == 0);
    CHECK(e1.winding_delta == 0);
    CHECK(e1.poly_type == polygon_type_subject);
    CHECK(e1.side == edge_left);
}

TEST_CASE("test edge initialization - horizontal segment") {
    mapbox::geometry::point<T> p1 = { 10, 10 };
    mapbox::geometry::point<T> p2 = { 100, 10 };
    edge<T> e1(p1, p2, polygon_type_subject);
    edge<T> e2(p2, p1, polygon_type_subject);

    CHECK(e1.bot.x == 10);
    CHECK(e1.bot.y == 10);
    CHECK(e1.curr.x == 10);
    CHECK(e1.curr.y == 10);
    CHECK(e1.top.x == 100);
    CHECK(e1.top.y == 10);
    CHECK(e1.dx == Approx(HORIZONTAL));

    CHECK(e2.bot.x == 100);
    CHECK(e2.bot.y == 10);
    CHECK(e2.curr.x == 100);
    CHECK(e2.curr.y == 10);
    CHECK(e2.top.x == 10);
    CHECK(e2.top.y == 10);
    CHECK(e2.dx == Approx(HORIZONTAL));
}

TEST_CASE("test edge initialization - vertical segment") {
    mapbox::geometry::point<T> p1 = { 10, 10 };
    mapbox::geometry::point<T> p2 = { 10, 100 };
    edge<T> e1(p1, p2, polygon_type_subject);
    edge<T> e2(p2, p1, polygon_type_subject);

    CHECK(e1.bot.x == 10);
    CHECK(e1.bot.y == 100);
    CHECK(e1.curr.x == 10);
    CHECK(e1.curr.y == 10);
    CHECK(e1.top.x == 10);
    CHECK(e1.top.y == 10);
    CHECK(e1.dx == Approx(0.0));

    CHECK(e2.bot.x == 10);
    CHECK(e2.bot.y == 100);
    CHECK(e2.curr.x == 10);
    CHECK(e2.curr.y == 100);
    CHECK(e2.top.x == 10);
    CHECK(e2.top.y == 10);
    CHECK(e2.dx == Approx(0.0));
}
