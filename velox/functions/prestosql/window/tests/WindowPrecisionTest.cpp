/*
* Copyright (c) Facebook, Inc. and its affiliates.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "velox/functions/prestosql/window/tests/WindowTestBase.h"

using namespace facebook::velox::exec::test;

namespace facebook::velox::window::test {

namespace {

class WindowPrecisionTest : public WindowTestBase {
protected:
 void testNtile(const std::vector<RowVectorPtr>& vectors) {
   // Tests ntile with constant value arguments.
   testNtileWithConstants(vectors, kOverClauses);
   // Tests ntile with a column.
   WindowTestBase::testWindowFunction(
       vectors, "ntile(c2)", kOverClauses, kFrameClauses);
 }

private:
 void testNtileWithConstants(
     const std::vector<RowVectorPtr>& vectors,
     const std::vector<std::string>& overClauses) {
   // These invocations of ntile check the following cases :
   // i) Constant buckets
   // ii) Number of buckets <, =, > number of rows in the partition.
   // iii) Number of buckets evenly divide (value 10) or not (other values).
   static const std::vector<std::string> kNtileInvocations = {
       "ntile(1)",
       "ntile(7)",
       "ntile(10)",
       "ntile(16)",
   };
   for (auto function : kNtileInvocations) {
     WindowTestBase::testWindowFunction(
         vectors, function, overClauses, kFrameClauses);
   }
 }
};

// Tests ntile with uniformly distributed data.
TEST_F(WindowPrecisionTest, repro) {
 std::cout << "Hello, world!" << std::endl;
}

}; // namespace
}; // namespace facebook::velox::window::test
