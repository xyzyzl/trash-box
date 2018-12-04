package com.company;

import java.util.*;
import java.io.*;

public class Main
{

	private static int N, xl, yl, xb, yb;
	private static HashMap<Line, Integer> cost;
	private static HashMap<Integer, ArrayList<Integer> > xy, yx; // for line transitions
	private static LinkedList<Line> q;
	public static void main(String[] args) throws IOException
	{
		cost = new HashMap<Line, Integer>();
		xy = new HashMap<Integer, ArrayList<Integer> >();
		yx = new HashMap<Integer, ArrayList<Integer> >();
		q = new LinkedList<Line>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		xl = Integer.parseInt(st.nextToken());
		yl = Integer.parseInt(st.nextToken());
		xb = Integer.parseInt(st.nextToken());
		yb = Integer.parseInt(st.nextToken());
		q.add(new Line(xl, true));
		q.add(new Line(yl, false));
		cost.put(new Line(xl, true), 0);
		cost.put(new Line(yl, false), 0);
		for(int i = 0; i < N; i++)
		{
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			if(!xy.containsKey(x))
			{
				xy.put(x, new ArrayList<Integer>());
			}
			xy.get(x).add(y);
			if(!yx.containsKey(y))
			{
				yx.put(y, new ArrayList<Integer>());
			}
			yx.get(y).add(x);
		}
		int min = -1;
		while(!q.isEmpty())
		{
			Line l = q.removeFirst();
			// System.out.println(cost.containsKey(l));
			// System.out.println((l.o ? 'x' : 'y') + " = " + l.c);
			if(l.o && l.c == xb)
			{
				min = cost.get(l);
				break;
			}
			if(!l.o && l.c == yb)
			{
				min = cost.get(l);
				break;
			}
			if(l.o)
			{
				// use xy map
				if(xy.containsKey(l.c))
				{
					for(int nx : xy.get(l.c))
					{
						Line res = new Line(nx, !l.o);
						if(!cost.containsKey(res))
						{
							cost.put(res, cost.get(l) + 1);
							q.add(res);
						}
					}
				}
			} else
			{
				// use yx map
				if(yx.containsKey(l.c))
				{
					for(int nx : yx.get(l.c))
					{
						Line res = new Line(nx, !l.o);
						if(!cost.containsKey(res))
						{
							cost.put(res, cost.get(l) + 1);
							q.add(res);
						}
					}
				}
			}
		}
		pw.println(min);
		pw.flush();
		pw.close();
	}

	private static class Line
	{
		int c;
		boolean o; // true = vertical, false = horizontal
		public Line(int c, boolean o)
		{
			this.c=c;
			this.o=o;
		}
		public int hashCode()
		{
			final int PRIME = 31;
			int res = 1;
			res = PRIME * res + (o ? 1237 : 1231);
			res = PRIME * res + c;
			return res;
		}
		public boolean equals(Object obj)
		{
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Line other = (Line) obj;
			if (o != other.o)
				return false;
			if (c != other.c)
				return false;
			return true;
		}
	}

}
