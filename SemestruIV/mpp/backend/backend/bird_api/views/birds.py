from django.shortcuts import render
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework import status
from ..models import Bird
from ..serializers import BirdSerializer

# Create your views operations here.
@api_view(['GET'])
def bird_list(request):
    birds = Bird.objects.all()
    print ("type:birds",type(birds))
    serializer = BirdSerializer(birds, many=True)
    return Response(serializer.data)

@api_view(['GET'])
def bird_detail(request, pk):
    try:
        bird = Bird.objects.get(id=pk)
    except Bird.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    
    serializer = BirdSerializer(bird, many=False)
    
    return Response(serializer.data, status=status.HTTP_200_OK)

@api_view(['POST'])
def bird_create(request):
    serializer = BirdSerializer(data=request.data)

    if serializer.is_valid():
        serializer.save()
        return Response(serializer.data, status=status.HTTP_201_CREATED)
    return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@api_view(['PUT'])
def bird_update(request, pk):
    try:
        bird = Bird.objects.get(id=pk)
    except Bird.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    
    serializer = BirdSerializer(instance=bird, data=request.data)
    
    if serializer.is_valid():
        serializer.save()
        return Response(serializer.data, status=status.HTTP_200_OK)
    return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@api_view(['DELETE'])
def bird_delete(request, pk):
    try:
        bird = Bird.objects.get(id=pk)
    except Bird.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    
    bird.delete()
    
    return Response(status=status.HTTP_204_NO_CONTENT)

@api_view(['GET'])
def bird_sort(request):
    birds = Bird.objects.all().order_by("color")
    serializer = BirdSerializer(birds, many=True)
    return Response(serializer.data)

@api_view(['GET'])
def bird_paginated(request):
    birds = Bird.objects.all()
    page = int(request.query_params.get('page', 1))
    page_size = int(request.query_params.get('page_size', 2))
    start = (page - 1) * page_size
    end = page * page_size
    serializer = BirdSerializer(birds[start:end], many=True)
    return Response(serializer.data)

@api_view(['GET'])
def bird_count(request):
    birds = Bird.objects.all()
    count = birds.count()
    return Response({'count': count})

@api_view(['GET'])
def bird_filter(request):
    colorString = request.query_params.get('color', '')
    birds = Bird.objects.filter(color__icontains=colorString)
    serializer = BirdSerializer(birds, many=True)
    print("colorstring",colorString)
    return Response(serializer.data)

@api_view(['GET'])
def bird_piechart(request):
    birds = Bird.objects.all()
    colors = [bird.color for bird in birds]
    color_counts = {}
    for color in colors:
        if color in color_counts:
            color_counts[color] += 1
        else:
            color_counts[color] = 1
    return Response(color_counts)




