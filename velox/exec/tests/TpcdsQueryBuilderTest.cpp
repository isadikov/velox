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
#include <iostream>
#include "velox/exec/tests/utils/OperatorTestBase.h"
#include "velox/exec/tests/utils/TpcdsQueryBuilder.h"
#include "velox/exec/tests/utils/TempDirectoryPath.h"

using namespace facebook::velox;
using namespace facebook::velox::exec::test;

class TpcdsQueryBuilderTest : public OperatorTestBase {
};

TEST_F(TpcdsQueryBuilderTest, test) {
  TpcdsQueryBuilder builder(dwio::common::FileFormat::PARQUET);
  builder.initialize("/tmp");
  auto plan = builder.getQueryPlan(1);
  std::cout << "Plan: " << plan.plan->toString(true) << std::endl;
}