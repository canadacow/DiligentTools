/*
 *  Copyright 2019-2020 Diligent Graphics LLC
 *  Copyright 2015-2019 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *      http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

#include "../../../DiligentCore/Primitives/interface/FileStream.h"
#include "../../../DiligentCore/Graphics/GraphicsEngine/interface/RenderDevice.h"
#include "../../../DiligentCore/Graphics/GraphicsEngine/interface/Texture.h"
#include "Image.hpp"

namespace Diligent
{
// clang-format off
/// Texture loading information
struct TextureLoadInfo
{
    /// Texture name passed over to the texture creation method
    const Char* Name                    = nullptr;
        
    /// Usage
    USAGE Usage                         = USAGE_STATIC;

    /// Bind flags
    BIND_FLAGS BindFlags                = BIND_SHADER_RESOURCE;

    /// Number of mip levels
    Uint32 MipLevels                    = 0;

    /// CPU access flags
    CPU_ACCESS_FLAGS CPUAccessFlags     = CPU_ACCESS_NONE;

    /// Flag indicating if this texture uses sRGB gamma encoding
    Bool IsSRGB                         = False;

    /// Flag indicating that the procedure should generate lower mip levels
    Bool GenerateMips                   = True;

    /// Texture format
    TEXTURE_FORMAT Format               = TEX_FORMAT_UNKNOWN;

    explicit TextureLoadInfo(const Char*         _Name,
                             USAGE               _Usage             = TextureLoadInfo{}.Usage,
                             BIND_FLAGS          _BindFlags         = TextureLoadInfo{}.BindFlags,
                             Uint32              _MipLevels         = TextureLoadInfo{}.MipLevels,
                             CPU_ACCESS_FLAGS    _CPUAccessFlags    = TextureLoadInfo{}.CPUAccessFlags,
                             Bool                _IsSRGB            = TextureLoadInfo{}.IsSRGB,
                             Bool                _GenerateMips      = TextureLoadInfo{}.GenerateMips,
                             TEXTURE_FORMAT      _Format            = TextureLoadInfo{}.Format) :
        Name            {_Name},
        Usage           {_Usage},
        BindFlags       {_BindFlags},
        MipLevels       {_MipLevels},
        CPUAccessFlags  {_CPUAccessFlags},
        IsSRGB          {_IsSRGB},
        GenerateMips    {_GenerateMips},
        Format          {_Format}
    {}

    TextureLoadInfo(){};
};
// clang-format on

/// Creates a texture from 2D image

/// \param [in] pSrcImage - Pointer to the source image data
/// \param [in] TexLoadInfo - Texture loading information
/// \param [in] pDevice - Render device that will be used to create the texture
/// \param [out] ppTexture - Memory location where pointer to the created texture will be stored
void CreateTextureFromImage(Image*                 pSrcImage,
                            const TextureLoadInfo& TexLoadInfo,
                            IRenderDevice*         pDevice,
                            ITexture**             ppTexture);

/// Creates a texture from DDS data blob

/// \param [in] pDDSData - Pointer to the DDS data blob
/// \param [in] TexLoadInfo - Texture loading information
/// \param [in] pDevice - Render device that will be used to create the texture
/// \param [out] ppTexture - Memory location where pointer to the created texture will be stored
void CreateTextureFromDDS(IDataBlob*             pDDSData,
                          const TextureLoadInfo& TexLoadInfo,
                          IRenderDevice*         pDevice,
                          ITexture**             ppTexture);


/// Creates a texture from KTX data blob

/// \param [in] pKTXData    - Pointer to the KTX data blob
/// \param [in] TexLoadInfo - Texture loading information
/// \param [in] pDevice     - Render device that will be used to create the texture
/// \param [out] ppTexture  - Memory location where pointer to the created texture will be stored
void CreateTextureFromKTX(IDataBlob*             pKTXData,
                          const TextureLoadInfo& TexLoadInfo,
                          IRenderDevice*         pDevice,
                          ITexture**             ppTexture);
}; // namespace Diligent
