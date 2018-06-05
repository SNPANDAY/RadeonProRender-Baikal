
/**********************************************************************
 Copyright (c) 2017 Advanced Micro Devices, Inc. All rights reserved.

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ********************************************************************/

#pragma once

#include "ImGUI/imgui.h"
#include "SceneGraph/uberv2material.h"
#include "uber_graph.h"

class MaterialExplorer
{
public:
    using InputMap = Baikal::InputMap;
    using UberV2Material = Baikal::UberV2Material;
    using Ptr = std::shared_ptr<MaterialExplorer>;
    using LayerDesc = std::pair<Baikal::UberV2Material::Layers, std::vector<std::string>>;

    static Ptr Create(UberV2Material::Ptr material);

    void ChangeLayer();

protected:
    MaterialExplorer(UberV2Material::Ptr material);

private:
    static std::vector<LayerDesc> GetUberLayersDesc();

    UberV2Material::Ptr m_material;
    std::vector<LayerDesc> m_layers;
    UberGraph::Ptr m_uber_graph;
};