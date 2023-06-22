#ifndef ISOPATRIC_CORE_LAYERSTACK_H
#define ISOPATRIC_CORE_LAYERSTACK_H

#include "Layer.h"

namespace isopatric::core
{
	class LayerStack
	{
	 public:
		LayerStack() = default;
		~LayerStack();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);
		void popLayer(Layer* layer);
		void popOverlay(Layer* layer);

		std::vector<Layer*>::iterator begin() { return mLayers.begin(); }
		std::vector<Layer*>::iterator end() { return mLayers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin() { return mLayers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return mLayers.rend(); }

	 private:
		std::vector<Layer*> mLayers;
		unsigned int mOverlayIndex = 0;
	};
}

#endif // ISOPATRIC_CORE_LAYERSTACK_H
