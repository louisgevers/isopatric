#include "LayerStack.h"

namespace isopatric::core
{
	LayerStack::~LayerStack()
	{
		for (Layer* layer : mLayers)
		{
			layer->onDetach();
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer)
	{
		mLayers.emplace(mLayers.begin() + mOverlayIndex, layer);
		mOverlayIndex++;
		layer->onAttach();
	}

	void LayerStack::pushOverlay(Layer* layer)
	{
		mLayers.emplace_back(layer);
		layer->onAttach();
	}

	void LayerStack::popLayer(Layer* layer)
	{
		auto it = std::find(mLayers.begin(), mLayers.begin() + mOverlayIndex, layer);
		if (it != mLayers.end())
		{
			layer->onDetach();
			mLayers.erase(it);
			mOverlayIndex--;
		}
	}

	void LayerStack::popOverlay(Layer* layer)
	{
		auto it = std::find(mLayers.begin() + mOverlayIndex, mLayers.end(), layer);
		if (it != mLayers.end())
		{
			layer->onDetach();
			mLayers.erase(it);
		}
	}
}