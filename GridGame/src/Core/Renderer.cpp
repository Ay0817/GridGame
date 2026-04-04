#include "../../include/Renderer.hpp"

Renderer::Renderer(int layer, int order)
	: Component()
	, _layer(layer)
	, _order(order)
{}

int Renderer::GetLayer() const {
	return _layer;
}

void Renderer::SetLayer(int layer) {
	_layer = layer;;
}

int Renderer::GetOrder() const {
	return _order;
}

void Renderer::SetOrder(int order) {
	_order = order;
}
